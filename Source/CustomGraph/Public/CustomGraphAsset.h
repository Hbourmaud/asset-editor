#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CustomGraphAsset.generated.h"

UCLASS(BlueprintType)
class CUSTOMGRAPH_API UCustomGraphAsset : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = "Custom Graph")
    FString GraphName;

    UCustomGraphAsset()
    {
        GraphName = TEXT("New Graph");
    }
};
