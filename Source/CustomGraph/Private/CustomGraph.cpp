#include "CustomGraph.h"

IMPLEMENT_MODULE(FCustomGraph, CustomGraph)

void FCustomGraph::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("CustomGraph module loaded!"));
}

void FCustomGraph::ShutdownModule()
{
}
