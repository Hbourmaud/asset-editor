#include "CustomGraphSchemaAction.h"

UEdGraphNode* FCustomGraphSchemaAction_NewNode::PerformAction(
    UEdGraph* ParentGraph,
    UEdGraphPin* FromPin,
    const FVector2D Location,
    bool bSelectNewNode
)
{
    UCustomGraphNode* Node = NewObject<UCustomGraphNode>(ParentGraph, UCustomGraphNode::StaticClass());
    Node->NodePosX = Location.X;
    Node->NodePosY = Location.Y;

    Node->AllocateDefaultPins();

    ParentGraph->AddNode(Node);

    return Node;
}