#pragma once

#include "CoreMinimal.h"
#include "SGraphPin.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class SCustomGraphPin : public SGraphPin
{
public:
	SLATE_BEGIN_ARGS(SCustomGraphPin) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UEdGraphPin* InPin);

protected:
	virtual const FSlateBrush* GetPinIcon() const override
	{
		return SGraphPin::GetPinIcon();
	}
};
