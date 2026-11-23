// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/Q/QueuedFile.h; GPL-3.0.
// QueuedFile: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// QueuedFileLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/QueuedFileLayout.h.
// QueuedFileStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "../bscore/IOTaskStorageLayout.h"
#include "../bscore/BSFixedStringStorageLayout.h"

namespace ResearchLayouts {
class QueuedFileStorageLayout;
class QueuedFileStorageLayout : public IOTaskStorageLayout {
public:
    virtual ~QueuedFileStorageLayout();
    std::uint64_t unk18;
    NiPointerStorageLayout<QueuedFileStorageLayout> parent;
    std::uint64_t children;
    std::uint64_t unk30;
};
static_assert(sizeof(QueuedFileStorageLayout) == 56, "community represented size");
static_assert(offsetof(QueuedFileStorageLayout, unk18) == 24, "unk18 offset");
static_assert(offsetof(QueuedFileStorageLayout, parent) == 32, "parent offset");
static_assert(offsetof(QueuedFileStorageLayout, children) == 40, "children offset");
static_assert(offsetof(QueuedFileStorageLayout, unk30) == 48, "unk30 offset");
}
