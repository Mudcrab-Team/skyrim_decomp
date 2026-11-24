// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x69f990 (skyrim_shared/actors/Actor_69f990): source copied, names replaced by placeholders.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5912
// 0x672e00 Owner672e00::Function672e00
#include "Owner672e00.h"

// guess: same compiled code as matched 0x69f990 apart from relocated fields; its role here is not established.
bool Owner672e00::Function672e00(unsigned char entry) const { return currentProcess && currentProcess->HasPerkEntries(entry); }
