#pragma once
#include "EdGraphUtilities.h"
#include "CustomGraphNode.h"
#include "GraphNodeCustomNode.h"

class FCustomNodeFactory : public FGraphPanelNodeFactory
{
public:
    virtual TSharedPtr<SGraphNode> CreateNode(UEdGraphNode* Node) const override;
};
