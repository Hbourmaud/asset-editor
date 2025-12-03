#pragma once
#include "SGraphNode.h"
#include "CustomGraphPin.h"

class SGraphNodeCustomNode : public SGraphNode
{
public:
    SLATE_BEGIN_ARGS(SGraphNodeCustomNode) {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, UEdGraphNode* InNode);

    virtual void CreatePinWidgets() override;
};
