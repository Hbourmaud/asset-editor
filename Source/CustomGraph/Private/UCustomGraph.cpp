#include "UCustomGraph.h"
#include "CustomGraphSchema.h"

UCustomGraph::UCustomGraph()
{
    Schema = UCustomGraphSchema::StaticClass();
}

void UCustomGraph::PostInitProperties()
{
    Super::PostInitProperties();

    if (!Schema)
    {
        Schema = UCustomGraphSchema::StaticClass();
    }
}