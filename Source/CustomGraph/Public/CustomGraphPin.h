#pragma once

#include "CoreMinimal.h"
#include "SGraphPin.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class SCustomGraphPin : public SGraphPin
{
public:
	SLATE_BEGIN_ARGS(SCustomGraphPin) {}
		SLATE_ARGUMENT(UEdGraphPin*, PinObj)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

protected:
	virtual TSharedRef<FDragDropOperation> SpawnPinDragEvent(
		const TSharedRef<class SGraphPanel>& InGraphPanel,
		const TArray<TSharedRef<SGraphPin>>& InStartingPins
	) override;

	virtual const FSlateBrush* GetPinIcon() const override
	{
		return SGraphPin::GetPinIcon();
	}
};
