#include "CustomGraphFactory.h"
#include "CustomGraphAsset.h"

UCustomGraphFactory::UCustomGraphFactory()
{
    SupportedClass = UCustomGraphAsset::StaticClass();
    bCreateNew = true;
    bEditAfterNew = true;
}

UObject* UCustomGraphFactory::FactoryCreateNew(
    UClass* Class,
    UObject* InParent,
    FName Name,
    EObjectFlags Flags,
    UObject* Context,
    FFeedbackContext* Warn
)
{
    return NewObject<UCustomGraphAsset>(InParent, Class, Name, Flags);
}
