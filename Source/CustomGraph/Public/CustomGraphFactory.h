#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "CustomGraphFactory.generated.h"

UCLASS()
class CUSTOMGRAPH_API UCustomGraphFactory : public UFactory
{
    GENERATED_BODY()

public:
    UCustomGraphFactory();

    virtual UObject* FactoryCreateNew(
        UClass* Class,
        UObject* InParent,
        FName Name,
        EObjectFlags Flags,
        UObject* Context,
        FFeedbackContext* Warn
    ) override;

    virtual bool ShouldShowInNewMenu() const override
    {
        return true;
    }
};
