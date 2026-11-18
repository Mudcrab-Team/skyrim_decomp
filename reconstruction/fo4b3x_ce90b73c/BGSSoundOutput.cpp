// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BGSSoundOutput::DoGetHasSpeakerBias: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:91
// 0x32b600 BGSSoundOutput::DoGetHasSpeakerBias
#include "BGSSoundOutput.h"
bool BGSSoundOutput::DoGetHasSpeakerBias() const { return type==Type::kDefinedSpeakerOutput; }
