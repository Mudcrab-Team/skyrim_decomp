// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BGSMusicType::DoApplyDuckingAttenuation: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target interface layout.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicType.cpp:70
// names: GUESS(low); qualified name is unverified.
// 0x327ec0 BGSMusicType::DoApplyDuckingAttenuation
#include "BGSMusicType.h"
void BGSMusicType::DoApplyDuckingAttenuation(unsigned short attenuation) { if (currentTrackIndex < tracks.size) tracks.data[currentTrackIndex]->DoSetDuckingAttenuation(attenuation); }
