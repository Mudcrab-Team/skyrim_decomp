// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x69f9c0 (skyrim_shared/actors/Actor_69f9c0): source copied, names replaced by placeholders.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5919
// 0x69f970 Owner69f970::Function69f970
#include "Owner69f970.h"

// guess: same compiled code as matched 0x69f9c0 apart from relocated fields; its role here is not established.
void Owner69f970::Function69f970(unsigned char entry, PerkEntryVisitor& visitor) const { if (currentProcess) currentProcess->ForEachPerkEntry(entry, visitor); }
