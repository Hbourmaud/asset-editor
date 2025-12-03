#include "CustomNodeFactory.h"

TSharedPtr<SGraphNode> FCustomNodeFactory::CreateNode(UEdGraphNode* Node) const
{
        if (UCustomGraphNode* CustomNode = Cast<UCustomGraphNode>(Node))
        {
            return SNew(SGraphNodeCustomNode, CustomNode);
        }
        return nullptr;
    }