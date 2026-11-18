// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/BSTask.h; GPL-3.0.
// BSTask: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSTaskLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class BSTaskLayout {
public:
    virtual ~BSTaskLayout();
    volatile std::int32_t refCount;
    std::uint32_t unk0C;
    std::uint64_t unk10;
};
static_assert(sizeof(BSTaskLayout) == 24, "community represented size");
static_assert(offsetof(BSTaskLayout, refCount) == 8, "refCount offset");
static_assert(offsetof(BSTaskLayout, unk0C) == 12, "unk0C offset");
static_assert(offsetof(BSTaskLayout, unk10) == 16, "unk10 offset");
}
