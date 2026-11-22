// Source exposure: mixed (pinned image listing and sibling hint).
// Code origin: existing sibling-adapted method plus original reconstruction of Functioncca630.
// Sibling source: fo4-private@1b765c70 src/BSAudio/BSAudioManager.cpp:75
// BSAudioManager::QPlatformInstance: SIBLING(fo4-private@1b765c70, author-permission)
// BSAudioManager, BSAudio, platformInstance, audioManagerInstance, Functioncca630: GUESS(low)
#pragma once
class BSAudio;
extern BSAudio* platformInstance;
extern void* audioManagerInstance;
class BSAudioManager {
public:
    static BSAudio& QPlatformInstance();
    static bool Functioncca630();
};
