#pragma once

#include "Modules/ModuleManager.h"

class FCustomGraph : public IModuleInterface
{
public:

    virtual void StartupModule() override;

    virtual void ShutdownModule() override;
};
