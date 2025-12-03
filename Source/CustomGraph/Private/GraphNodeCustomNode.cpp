#include "GraphNodeCustomNode.h"

void SGraphNodeCustomNode::Construct(const FArguments& InArgs, UEdGraphNode* InNode)
{
    GraphNode = InNode;

    SetCursor(EMouseCursor::CardinalCross);
    UpdateGraphNode();
}

void SGraphNodeCustomNode::CreatePinWidgets()
{
    for (UEdGraphPin* Pin : GraphNode->Pins)
    {
        if (Pin && !Pin->bHidden)
        {
            TSharedPtr<SGraphPin> NewPin = SNew(SCustomGraphPin, Pin);

            this->AddPin(NewPin.ToSharedRef());
        }
    }
}
