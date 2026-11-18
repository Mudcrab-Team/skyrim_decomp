// BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyShift: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/TESForms/Gameplay/BGSStandardSoundDef.cpp:265.
// BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyVariance: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/TESForms/Gameplay/BGSStandardSoundDef.cpp:271.
// BGSStandardSoundDef::SoundPlaybackCharacteristics::GetPriority: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/TESForms/Gameplay/BGSStandardSoundDef.cpp:277.
// BGSStandardSoundDef::SoundPlaybackCharacteristics::GetStaticAttenuation: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/TESForms/Gameplay/BGSStandardSoundDef.cpp:289.
// Semantic names and types: GUESS(low)
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// 0x32c210 BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyShift
// 0x32c220 BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyVariance
// 0x32c230 BGSStandardSoundDef::SoundPlaybackCharacteristics::GetPriority
// 0x32c250 BGSStandardSoundDef::SoundPlaybackCharacteristics::GetStaticAttenuation
#include "BGSStandardSoundDef.h"
std::uint8_t BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyShift() { return frequencyShift; }
std::uint8_t BGSStandardSoundDef::SoundPlaybackCharacteristics::GetFrequencyVariance() { return frequencyVariance; }
std::uint8_t BGSStandardSoundDef::SoundPlaybackCharacteristics::GetPriority() { return priority; }
std::uint16_t BGSStandardSoundDef::SoundPlaybackCharacteristics::GetStaticAttenuation() { return staticAttenuation; }
