#include "CustomGraphNode.h"
#include "GraphNodeCustomNode.h"
#include "EdGraph/EdGraphPin.h"

void UCustomGraphNode::AllocateDefaultPins()
{
    UE_LOG(LogTemp, Warning, TEXT("AllocateDefaultPins CALLED"));
    CreatePin(EGPD_Input, FName(TEXT("Custom")), TEXT("Input"));
    CreatePin(EGPD_Output, FName(TEXT("Custom")), TEXT("Output"));

    for (UEdGraphPin* Pin : Pins)
    {
        UE_LOG(LogTemp, Warning, TEXT("Pin: %s, Category=%s, Dir=%s"),
            *Pin->PinName.ToString(),
            *Pin->PinType.PinCategory.ToString(),
            Pin->Direction == EGPD_Input ? TEXT("Input") : TEXT("Output"));
    }
}

FText UCustomGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return FText::FromString(TEXT("Custom Node"));
}

TSharedPtr<SGraphNode> UCustomGraphNode::CreateVisualWidget()
{
    return SNew(SGraphNodeCustomNode, this);
}
