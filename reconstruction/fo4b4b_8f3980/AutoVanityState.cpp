// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling hint.
// AutoVanityState::End: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/AutoVanityState.cpp:61
// names: GUESS(low); names and original signatures are tentative.
// 0x8f3980 AutoVanityState::End
#include "AutoVanityState.h"
void AutoVanityState::End() { SendUptimeEvent(resumeMessage); }
