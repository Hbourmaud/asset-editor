#include "CustomGraphNode.h"
#include "EdGraph/EdGraphPin.h"

void UCustomGraphNode::AllocateDefaultPins()
{
    CreatePin(EGPD_Input, TEXT("Float"), TEXT("Input"));

    CreatePin(EGPD_Output, TEXT("Float"), TEXT("Output"));
}

FText UCustomGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return FText::FromString(TEXT("Custom Node"));
}
