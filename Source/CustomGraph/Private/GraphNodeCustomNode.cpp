#include "GraphNodeCustomNode.h"

void SGraphNodeCustomNode::Construct(const FArguments& InArgs, UEdGraphNode* InNode)
{
    GraphNode = InNode;

    SGraphNode::Construct();
    UpdateGraphNode();
}

void SGraphNodeCustomNode::CreatePinWidgets()
{
    for (UEdGraphPin* Pin : GraphNode->Pins)
    {
        TSharedPtr<SGraphPin> NewPin = CreatePinWidget(Pin);
        AddPin(NewPin.ToSharedRef());
    }
}
