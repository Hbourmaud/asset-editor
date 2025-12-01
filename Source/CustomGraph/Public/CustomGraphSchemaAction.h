#pragma once

#include "EdGraph/EdGraphSchema.h"
#include "CustomGraphNode.h"

class FCustomGraphSchemaAction_NewNode : public FEdGraphSchemaAction
{
public:
    FCustomGraphSchemaAction_NewNode()
        : FEdGraphSchemaAction(
            FText::FromString("Custom"),
            FText::FromString("Add Custom Node"),
            FText::FromString("Adds a new custom node"),
            0)
    {
    }

    virtual UEdGraphNode* PerformAction(
        UEdGraph* ParentGraph,
        UEdGraphPin* FromPin,
        const FVector2D Location,
        bool bSelectNewNode
    ) override
    {
        UCustomGraphNode* Node = NewObject<UCustomGraphNode>(ParentGraph, UCustomGraphNode::StaticClass());
        Node->NodePosX = Location.X;
        Node->NodePosY = Location.Y;

        Node->AllocateDefaultPins();

        ParentGraph->AddNode(Node);

        return Node;
    }
};
