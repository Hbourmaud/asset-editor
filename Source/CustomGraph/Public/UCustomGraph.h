#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraph.h"
#include "UCustomGraph.generated.h"

UCLASS()
class CUSTOMGRAPH_API UCustomGraph : public UEdGraph
{
    GENERATED_BODY()

public:
    UCustomGraph();

    virtual void PostInitProperties() override;
};
