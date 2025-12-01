#include "CustomGraphEditorToolkit.h"
#include "CustomGraphAsset.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphSchema.h"
#include "GraphEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "ToolMenus.h"

#define LOCTEXT_NAMESPACE "FCustomGraphEditorToolkit"

static const FName GraphEditorTabId("CustomGraphEditor_MainTab");

void FCustomGraphEditorToolkit::InitEditor(const EToolkitMode::Type Mode,
    const TSharedPtr<IToolkitHost>& InitToolkitHost,
    UCustomGraphAsset* InGraphAsset)
{
    GraphAsset = InGraphAsset;

    if (GraphAsset)
    {
        GraphAsset->EnsureGraphExists();
    }

    EditingGraph = GraphAsset ? GraphAsset->Graph : nullptr;

    if (EditingGraph && !EditingGraph->Schema)
    {
        EditingGraph->Schema = UCustomGraphSchema::StaticClass();
        EditingGraph->Schema->AddToRoot();
    }

    const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("CustomGraphEditor_Layout_v1")
        ->AddArea
        (
            FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
            ->Split
            (
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

    return SNew(SGraphEditor)
        .GraphToEdit(EditingGraph)
        .Appearance(AppearanceInfo);
}

FName FCustomGraphEditorToolkit::GetToolkitFName() const
{
    return FName("CustomGraphEditor");
}

FText FCustomGraphEditorToolkit::GetBaseToolkitName() const
{
    return LOCTEXT("AppLabel", "Custom Graph Editor");
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
    FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

    InTabManager->RegisterTabSpawner(GraphEditorTabId,
        FOnSpawnTab::CreateLambda([this](const FSpawnTabArgs&)
            {
                if (!EditingGraph)
                {
                    return SNew(SDockTab)
                        .Label(LOCTEXT("GraphTab", "Graph"));
                }

                return SNew(SDockTab)
                    .Label(LOCTEXT("GraphTab", "Graph"))
                    [
                        CreateGraphEditor()
                    ];
            }));

}


void FCustomGraphEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
    FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
    InTabManager->UnregisterTabSpawner(GraphEditorTabId);
}

#undef LOCTEXT_NAMESPACE
