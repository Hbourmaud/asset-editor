#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CustomGraphSchema.h"
#include "UCustomGraph.h"
#include "CustomGraphAsset.generated.h"

UCLASS(BlueprintType)
class CUSTOMGRAPH_API UCustomGraphAsset : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = "Custom Graph")
    FString GraphName;

    UPROPERTY()
    UCustomGraph* Graph;

    UCustomGraphAsset()
    {
        GraphName = TEXT("New Graph");
        Graph = nullptr;
    }

    void EnsureGraphExists()
    {
        if (!Graph)
        {
            Graph = NewObject<UCustomGraph>(this, UCustomGraph::StaticClass(), FName("Graph"), RF_Transactional);
            Graph->Schema = UCustomGraphSchema::StaticClass();
        }
    }
};
