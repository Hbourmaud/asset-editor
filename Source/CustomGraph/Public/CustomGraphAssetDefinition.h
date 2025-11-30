#pragma once

#include "CoreMinimal.h"
#include "AssetDefinitionDefault.h"
#include "CustomGraphAsset.h"
#include "CustomGraphAssetDefinition.generated.h"

UCLASS()
class CUSTOMGRAPH_API UAssetDefinition_CustomGraph : public UAssetDefinitionDefault
{
    GENERATED_BODY()

public:

    virtual FText GetAssetDisplayName() const override
    {
        return NSLOCTEXT("AssetDefinition", "CustomGraphAsset", "Custom Graph");
    }

    virtual TSoftClassPtr<UObject> GetAssetClass() const override
    {
        return UCustomGraphAsset::StaticClass();
    }

    virtual FAssetCategoryPath GetAssetCategoryPath() const
    {
        return FAssetCategoryPath(NSLOCTEXT("AssetCategory", "CustomGraph", "Custom"));
    }

    virtual FLinearColor GetAssetColor() const override
    {
        return FLinearColor(0.0f, 0.8f, 1.0f);
    }
};
