#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "CustomGraphSchemaAction.h"
#include "CustomGraphSchema.generated.h"

UCLASS()
class CUSTOMGRAPH_API UCustomGraphSchema : public UEdGraphSchema
{
    GENERATED_BODY()

public:
    UCustomGraphSchema() {}

    virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;

    virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;

    virtual bool TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const override;

    virtual FLinearColor GetPinTypeColor(const FEdGraphPinType& PinType) const override;
};
