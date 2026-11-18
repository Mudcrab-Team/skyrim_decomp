// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BGSMusicType::DoClearDucking: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target interface layout.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicType.cpp:77
// names: GUESS(low); qualified name is unverified.
// 0x327ef0 BGSMusicType::DoClearDucking
#include "BGSMusicType_327ef0.h"
void BGSMusicType::DoClearDucking() { if (currentTrackIndex < tracks.size) tracks.data[currentTrackIndex]->DoClearDucking(); }
