#include "CustomNodeFactory.h"

TSharedPtr<SGraphNode> FCustomNodeFactory::CreateNode(UEdGraphNode* Node) const
{
        UE_LOG(LogTemp, Warning, TEXT("createnode first calld+ed"));

        if (UCustomGraphNode* CustomNode = Cast<UCustomGraphNode>(Node))
        {
            return SNew(SGraphNodeCustomNode, CustomNode);
        }
        return nullptr;
    }