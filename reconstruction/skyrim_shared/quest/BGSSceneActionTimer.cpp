// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x3ad170 BGSSceneActionTimer::Unk_0D
// 0x3ad400 BGSSceneActionTimer::~BGSSceneActionTimer
#include "BGSSceneActionTimer.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BGSSceneActionTimer::BGSSceneActionTimer()
{
}

// TODO body: RVA 0x3ad400, 43 bytes, BGSSceneActionTimer::~BGSSceneActionTimer; compared as the
// scalar deleting destructor. If the target calls a separate destructor, keep only the declaration
// and delete this definition (cookbook rule 18).
BGSSceneActionTimer::~BGSSceneActionTimer() {}
