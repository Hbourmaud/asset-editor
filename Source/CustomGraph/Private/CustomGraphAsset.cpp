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

    Graph->Schema = UCustomGraphSchema::StaticClass();
    UE_LOG(LogTemp, Warning, TEXT("Runtime schema: %s"), *Graph->GetSchema()->GetName());
}
