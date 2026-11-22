// Source exposure: mixed (pinned image listing and sibling hint).
// Code origin: existing sibling-adapted method plus original reconstruction of Functioncca630.
// Sibling source: fo4-private@1b765c70 src/BSAudio/BSAudioManager.cpp:75
// Adapted bodies: QPlatformInstance from fo4-private@1b765c70; Functioncca630 original.
// 0xcca620 BSAudioManager::QPlatformInstance
// 0xcca630 BSAudioManager::Functioncca630
#include "BSAudioManager.h"
BSAudio& BSAudioManager::QPlatformInstance() { return *platformInstance; }
bool BSAudioManager::Functioncca630() { return platformInstance != nullptr && audioManagerInstance != nullptr; }
