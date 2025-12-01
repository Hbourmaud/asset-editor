#include "CustomGraphSchema.h"
#include "CustomGraphNode.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraph/EdGraph.h"

void UCustomGraphSchema::CreateDefaultNodesForGraph(UEdGraph& Graph) const
{
    UCustomGraphNode* Node = NewObject<UCustomGraphNode>(&Graph);
    Node->NodePosX = 0;
    Node->NodePosY = 0;
    Graph.AddNode(Node);
}

const FPinConnectionResponse UCustomGraphSchema::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
    if (A == B)
    {
        return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Cannot connect pin to itself"));
    }

    return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT("Connection allowed"));
}

void UCustomGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
    if (ContextMenuBuilder.OwnerOfTemporaries)
    {
        TSharedPtr<FEdGraphSchemaAction> NewNodeAction = MakeShareable(new FCustomGraphSchemaAction_NewNode());
        ContextMenuBuilder.AddAction(NewNodeAction);
    }
}

