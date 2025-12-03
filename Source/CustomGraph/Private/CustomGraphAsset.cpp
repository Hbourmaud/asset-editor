#include "CustomGraphAsset.h"
#include "CustomGraphSchema.h"

UCustomGraphAsset::UCustomGraphAsset()
{
    GraphName = TEXT("New Graph");
    Graph = nullptr;
}

void UCustomGraphAsset::EnsureGraphExists()
{
    if (!Graph)
    {
        Graph = NewObject<UCustomGraph>(
            this,
            UCustomGraph::StaticClass(),
            TEXT("Graph"),
            RF_Transactional
        );
    }

    if (!Graph->Schema)
    {
        Graph->Schema = UCustomGraphSchema::StaticClass();
    }
}
