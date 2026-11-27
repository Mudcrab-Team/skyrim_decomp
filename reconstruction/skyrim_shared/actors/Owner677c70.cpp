// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x69f9c0 (skyrim_shared/actors/Actor_69f9c0): source copied, names replaced by placeholders.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5919
// 0x677c70 Owner677c70::Function677c70
#include "Owner677c70.h"

// guess: same compiled code as matched 0x69f9c0 apart from relocated fields; its role here is not established.
void Owner677c70::Function677c70(unsigned char entry, PerkEntryVisitor& visitor) const { if (currentProcess) currentProcess->ForEachPerkEntry(entry, visitor); }
