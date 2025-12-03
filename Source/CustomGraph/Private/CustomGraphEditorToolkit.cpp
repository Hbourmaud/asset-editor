#include "CustomGraphEditorToolkit.h"
#include "CustomGraphAsset.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphSchema.h"
#include "GraphEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "ToolMenus.h"

#define LOCTEXT_NAMESPACE "FCustomGraphEditorToolkit"

static const FName GraphEditorTabId("CustomGraphEditor_MainTab");

void FCustomGraphEditorToolkit::InitEditor(
    const EToolkitMode::Type Mode,
    const TSharedPtr<IToolkitHost>& InitToolkitHost,
    UCustomGraphAsset* InGraphAsset)
{
    GraphAsset = InGraphAsset;

    GraphAsset->EnsureGraphExists();

    EditingGraph = GraphAsset->Graph;

    if (!EditingGraph->Schema)
    {
        EditingGraph->Schema = UCustomGraphSchema::StaticClass();
    }

    const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("CustomGraphEditor_Layout_v1")
        ->AddArea(
            FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
            ->Split(
                FTabManager::NewStack()
                ->AddTab(GraphEditorTabId, ETabState::OpenedTab)
                ->SetHideTabWell(true)
            )
        );

    FAssetEditorToolkit::InitAssetEditor(
        Mode,
        InitToolkitHost,
        FName("CustomGraphEditor"),
        Layout,
        true,
        true,
        InGraphAsset
    );

    RegenerateMenusAndToolbars();
}

TSharedRef<SGraphEditor> FCustomGraphEditorToolkit::CreateGraphEditor()
{
    FGraphAppearanceInfo AppearanceInfo;
    AppearanceInfo.CornerText = LOCTEXT("GraphCornerText", "Custom Graph");

    SGraphEditor::FGraphEditorEvents GraphEvents;

    TSharedRef<SGraphEditor> GraphEditor = SNew(SGraphEditor)
        .GraphToEdit(EditingGraph)
        .Appearance(AppearanceInfo)
        .GraphEvents(GraphEvents)
        .IsEditable(true);

    GraphEditorWidget = GraphEditor;

    return GraphEditor;
}

FName FCustomGraphEditorToolkit::GetToolkitFName() const
{
    return FName("CustomGraphEditor");
}

FText FCustomGraphEditorToolkit::GetBaseToolkitName() const
{
    return LOCTEXT("AppLabel", "CustomGraphEditor");
}

FString FCustomGraphEditorToolkit::GetWorldCentricTabPrefix() const
{
    return TEXT("CustomGraph");
}

FLinearColor FCustomGraphEditorToolkit::GetWorldCentricTabColorScale() const
{
    return FLinearColor::White;
}

void FCustomGraphEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
        WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(
            LOCTEXT("WorkspaceMenu_CustomGraphEditor", "Custom Graph Editor"));

        FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

        InTabManager->RegisterTabSpawner(GraphEditorTabId,
            FOnSpawnTab::CreateSP(this, &FCustomGraphEditorToolkit::SpawnTab_GraphEditor))
            .SetDisplayName(LOCTEXT("GraphTab", "Graph"))
            .SetGroup(WorkspaceMenuCategory.ToSharedRef())
            .SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "GraphEditor.EventGraph_16x"));
}

void FCustomGraphEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
    FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
    InTabManager->UnregisterTabSpawner(GraphEditorTabId);
}

TSharedRef<SDockTab> FCustomGraphEditorToolkit::SpawnTab_GraphEditor(const FSpawnTabArgs& Args)
{
    check(Args.GetTabId() == GraphEditorTabId);

    TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
        .Label(LOCTEXT("GraphEditorTitle", "Graph"))
        [
            CreateGraphEditor()
        ];

    return SpawnedTab;
}

#undef LOCTEXT_NAMESPACE
