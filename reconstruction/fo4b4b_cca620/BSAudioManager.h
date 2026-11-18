// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling hint.
// BSAudioManager::QPlatformInstance: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/BSAudio/BSAudioManager.cpp:75
// BSAudioManager, BSAudio, platformInstance: GUESS(low); names and types are tentative.
#pragma once
class BSAudio;
extern BSAudio* platformInstance;
class BSAudioManager {
public:
    static BSAudio& QPlatformInstance();
};
