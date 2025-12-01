#pragma once

#include "CoreMinimal.h"
#include "CustomGraphSchema.h"
#include "Toolkits/AssetEditorToolkit.h"

class UCustomGraphAsset;
class UEdGraph;

class FCustomGraphEditorToolkit : public FAssetEditorToolkit
{
public:

    void InitEditor(const EToolkitMode::Type Mode,
        const TSharedPtr<class IToolkitHost>& InitToolkitHost,
        UCustomGraphAsset* InGraphAsset);

    virtual ~FCustomGraphEditorToolkit() override {}

    virtual FName GetToolkitFName() const override;
    virtual FText GetBaseToolkitName() const override;
    virtual FString GetWorldCentricTabPrefix() const override;
    virtual FLinearColor GetWorldCentricTabColorScale() const override;

    virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
    virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;

private:
    TSharedRef<class SGraphEditor> CreateGraphEditor();

    UEdGraph* EditingGraph = nullptr;
    UCustomGraphAsset* GraphAsset = nullptr;

    TSharedPtr<SGraphEditor> GraphEditorWidget;
};
