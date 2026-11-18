// Source exposure: binary-analysis (target access widths, RTTI and sized-delete arguments).
// Code origin: original minimal declarations from independently checked target field accesses and RTTI.
// TESRegionGrassObject, TESRegionObjectBase: EXE_RTTI
// TESRegionGrassObjectLayout, TESRegionObjectBaseLayout: GUESS(medium) STANDIN
// value08, value10: GUESS(low); each represents a separately observed eight-byte slot.
#pragma once
#include <cstddef>
#include "TESRegionObjectBaseLayout.h"
namespace ResearchLayouts {
class TESRegionGrassObjectLayout : public TESRegionObjectBaseLayout {
public:
    ~TESRegionGrassObjectLayout() override;
    void* value08;
    void* value10;
};
static_assert(sizeof(TESRegionGrassObjectLayout) == 24, "target sized-delete argument");
static_assert(offsetof(TESRegionGrassObjectLayout, value08) == 8, "observed eight-byte access");
static_assert(offsetof(TESRegionGrassObjectLayout, value10) == 16, "observed eight-byte access");
}
