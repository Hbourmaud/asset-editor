#include "CustomGraphSchema.h"
#include "CustomGraphNode.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraph/EdGraph.h"
#include "ConnectionDrawingPolicy.h"

const FPinConnectionResponse UCustomGraphSchema::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
    UE_LOG(LogTemp, Warning, TEXT("CanCreateConnection CALLED"));
    if (A == B)
    {
        return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Cannot connect pin to itself"));
    }

    return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT("Connection allowed"));
}

void UCustomGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
    if (ContextMenuBuilder.OwnerOfTemporaries)
    {
        TSharedPtr<FEdGraphSchemaAction> NewNodeAction = MakeShareable(new FCustomGraphSchemaAction_NewNode());
        ContextMenuBuilder.AddAction(NewNodeAction);
    }
}

bool UCustomGraphSchema::TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const
{
    UE_LOG(LogTemp, Warning, TEXT("TryCreateConnection CALLED"));

    const FPinConnectionResponse Response = CanCreateConnection(A, B);

    UE_LOG(LogTemp, Warning, TEXT("TryCreateConnection %s <-> %s | Response=%d"),
        *A->PinName.ToString(),
        *B->PinName.ToString(),
        (int32)Response.Response);

    if (Response.Response == CONNECT_RESPONSE_MAKE)
    {
        A->MakeLinkTo(B);
        return true;
    }

    return false;
}

FLinearColor UCustomGraphSchema::GetPinTypeColor(const FEdGraphPinType& PinType) const
{
    if (PinType.PinCategory == FName(TEXT("Custom")))
    {
        return FLinearColor(1.f, 0.5f, 0.f);
    }

    return FLinearColor::Red;
}

FConnectionDrawingPolicy* UCustomGraphSchema::CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, FSlateWindowElementList& InDrawElements, UEdGraph* InGraphObj) const
{
    return new FConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, InZoomFactor, InClippingRect, InDrawElements);
}