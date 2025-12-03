#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UCustomGraph.h"
#include "CustomGraphAsset.generated.h"

UCLASS(BlueprintType)
class CUSTOMGRAPH_API UCustomGraphAsset : public UObject
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, Category = "CustomGraph")
    FString GraphName;

    UPROPERTY()
    UCustomGraph* Graph;

    UCustomGraphAsset();

    void EnsureGraphExists();
};
