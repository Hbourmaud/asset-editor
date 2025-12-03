# Asset editor

An implementation of a custom graph editor system, allowing you to create custom assets with visual node-based graphs.

**Overview :** 
- Create custom asset (via Add -> Miscellaneous -> Custom Graph)
- Build custom editor
- Implement visual node graphs (Right click -> Add custom node)
- Handle graph schema

**Actual Issue :**

Actually, the connections between node pins aren't working because the overridden *CanCreateConnection* method isn't being called (in CustomGraphSchema).