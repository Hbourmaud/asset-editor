#include "CustomGraphPin.h"
#include "SGraphPanel.h"
#include "EdGraph/EdGraphPin.h"

void SCustomGraphPin::Construct(const FArguments& InArgs)
{
	UEdGraphPin* Pin = InArgs._PinObj;
	check(Pin);

	SGraphPin::Construct(SGraphPin::FArguments(), Pin);
}

TSharedRef<FDragDropOperation> SCustomGraphPin::SpawnPinDragEvent(
	const TSharedRef<SGraphPanel>& InGraphPanel,
	const TArray<TSharedRef<SGraphPin>>& InStartingPins
)
{
	return SGraphPin::SpawnPinDragEvent(InGraphPanel, InStartingPins);
}
