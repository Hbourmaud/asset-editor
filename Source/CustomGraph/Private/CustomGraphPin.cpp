#include "CustomGraphPin.h"
#include "SGraphPanel.h"
#include "EdGraph/EdGraphPin.h"

void SCustomGraphPin::Construct(const FArguments& InArgs, UEdGraphPin* InPin)
{
	check(InPin);

	SGraphPin::Construct(SGraphPin::FArguments(), InPin);
}