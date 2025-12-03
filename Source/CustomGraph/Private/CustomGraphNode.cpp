#include "CustomGraphNode.h"
#include "GraphNodeCustomNode.h"
#include "EdGraph/EdGraphPin.h"

void UCustomGraphNode::AllocateDefaultPins()
{
    CreatePin(EGPD_Input, FName(TEXT("Custom")), TEXT("Input"));
    CreatePin(EGPD_Output, FName(TEXT("Custom")), TEXT("Output"));
}

FText UCustomGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return FText::FromString(TEXT("Custom Node"));
}

TSharedPtr<SGraphNode> UCustomGraphNode::CreateVisualWidget()
{
    return SNew(SGraphNodeCustomNode, this);
}
