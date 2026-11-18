// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/BSAudio.h; GPL-3.0.
// BSAudio: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSAudioLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/BSAudioLayout.h.
// BSAudioStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class BSAudioListener;
class BSAudioStorageLayout {
public:
    virtual ~BSAudioStorageLayout();
    std::uint64_t unk08;
    BSAudioListener* audioListener;
};
static_assert(sizeof(BSAudioStorageLayout) == 24, "community represented size");
static_assert(offsetof(BSAudioStorageLayout, unk08) == 8, "unk08 offset");
static_assert(offsetof(BSAudioStorageLayout, audioListener) == 16, "audioListener offset");
}
