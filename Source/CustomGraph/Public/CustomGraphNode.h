#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "CustomGraphNode.generated.h"

UCLASS()
class CUSTOMGRAPH_API UCustomGraphNode : public UEdGraphNode
{
    GENERATED_BODY()

public:

    virtual void AllocateDefaultPins() override;

    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

    virtual FLinearColor GetNodeTitleColor() const override
    {
        return FLinearColor(0.f, 0.8f, 1.f);
    }
};
