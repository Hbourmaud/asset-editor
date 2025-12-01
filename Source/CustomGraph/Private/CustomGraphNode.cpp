#include "CustomGraphNode.h"
#include "EdGraph/EdGraphPin.h"

void UCustomGraphNode::AllocateDefaultPins()
{
    CreatePin(EGPD_Input, TEXT("CustomPinType"), TEXT("In"));

    CreatePin(EGPD_Output, TEXT("CustomPinType"), TEXT("Out"));
}

FText UCustomGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return FText::FromString(TEXT("Custom Node"));
}
