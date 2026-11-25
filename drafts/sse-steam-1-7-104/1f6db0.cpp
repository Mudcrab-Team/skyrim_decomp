// Near miss: 1.0 alignment distance | register-schedule
// Build: sse-steam-1-7-104; 0x1f6db0, 42 bytes.
// Exposure detail: (local binary analysis and permitted sibling source).
// Source exposure: mixed
// Code origin: adapted from fo4-private@1b765c70 src/Shared/Misc/BGSAttachTechniques.cpp:313; author-permission.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSAttachTechniques.cpp:313; body and policy naming lead only.
// BGSNamedNodeAttach, BGSNamedNodeAttach::DetachPolicy, BGSNamedNodeAttach::ActionPolicy: EXE_RTTI
// BGSNamedNodeAttach::Detach, BGSNamedNodeAttach::Process: SIBLING(fo4-private@1b765c70, author-permission)
// BSAttachTechniques, BSAttachTechniques::AttachTechniqueInput, RefAttachTechniqueInput: EXE_RTTI
// Return type is inferred as void; the sibling bool signature remains an alternative.
// Correspondence to the sibling method is inferred from local vtable ownership and policy use.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSAttachTechniques.cpp:300
// 0x1f6db0 BGSNamedNodeAttach::Detach

#include "include/1f6db0/BGSNamedNodeAttach_1f6db0.h"

// 0x1f6db0 BGSNamedNodeAttach::Detach
void BGSNamedNodeAttach::Detach(const BSAttachTechniques::AttachTechniqueInput& input)
{
    DetachPolicy policy;
    Process(input, policy);
}
