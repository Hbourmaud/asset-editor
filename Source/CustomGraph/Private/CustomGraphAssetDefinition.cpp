#include "CustomGraphAssetDefinition.h"

EAssetCommandResult UAssetDefinition_CustomGraph::OpenAssets(const FAssetOpenArgs& OpenArgs) const
{
    for (const FAssetData& AssetData : OpenArgs.Assets)
    {
        UObject* Obj = AssetData.GetAsset();
        if (UCustomGraphAsset* Graph = Cast<UCustomGraphAsset>(Obj))
        {
            TSharedRef<FCustomGraphEditorToolkit> Editor =
                MakeShared<FCustomGraphEditorToolkit>();

            Editor->InitEditor(
                EToolkitMode::Standalone,
                OpenArgs.ToolkitHost,
                Graph
            );
        }
    }

    return EAssetCommandResult::Handled;
}
