#include "CustomGraph.h"
#include "CustomNodeFactory.h"
#include "EdGraphUtilities.h"

IMPLEMENT_MODULE(FCustomGraph, CustomGraph)

TSharedPtr<FCustomNodeFactory> NodeFactory;

void FCustomGraph::StartupModule()
{
    NodeFactory = MakeShared<FCustomNodeFactory>();
    FEdGraphUtilities::RegisterVisualNodeFactory(NodeFactory);
}

void FCustomGraph::ShutdownModule()
{
    if (NodeFactory.IsValid())
    {
        FEdGraphUtilities::UnregisterVisualNodeFactory(NodeFactory);
        NodeFactory.Reset();
    }
}
