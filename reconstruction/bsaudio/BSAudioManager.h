// Source exposure: mixed (pinned image listing, community names and sibling source).
// Code origin: original declarations and the labelled sibling method.
// Sibling source: fo4-private@1b765c70 src/BSAudio/BSAudioManager.cpp:75
// BSAudioManager::QPlatformInstance: SIBLING(fo4-private@1b765c70, author-permission)
// BSAudioManager, BSAudio, platformInstance, audioManagerInstance: GUESS(low)
// BSAudioManager::QInitialized: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
class BSAudio;
extern BSAudio* platformInstance;
extern void* audioManagerInstance;
class BSAudioManager {
public:
    static BSAudio& QPlatformInstance();
    static bool QInitialized();
};
