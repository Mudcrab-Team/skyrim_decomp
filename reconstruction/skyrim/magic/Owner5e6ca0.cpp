// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x5c5d00 (skyrim/magic/DisguiseEffect): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DisguiseEffect.cpp:76
// 0x5e6ca0 Owner5e6ca0::Function5e6ca0
#include "Owner5e6ca0.h"

// guess: same compiled code as matched 0x5c5d00 apart from relocated fields; its role here is not established.
void Owner5e6ca0::Function5e6ca0(BGSLoadFormBuffer* buffer) { ActiveEffect::LoadGame(buffer); buffer->LoadDataEndian(&state, 4, 4); }
