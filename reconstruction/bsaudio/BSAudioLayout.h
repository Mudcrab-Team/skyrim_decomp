// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/BSAudio.h; GPL-3.0.
// BSAudio: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSAudioLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class BSAudioListener;
class BSAudioLayout {
public:
    virtual ~BSAudioLayout();
    std::uint64_t unk08;
    BSAudioListener* audioListener;
};
static_assert(sizeof(BSAudioLayout) == 24, "community represented size");
static_assert(offsetof(BSAudioLayout, unk08) == 8, "unk08 offset");
static_assert(offsetof(BSAudioLayout, audioListener) == 16, "audioListener offset");
}
