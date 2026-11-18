// Source exposure: binary-analysis (target access widths, RTTI and sized-delete arguments).
// Code origin: original minimal declarations from independently checked target field accesses and RTTI.
// TESRegionGrassObject, TESRegionObjectBase: EXE_RTTI
// TESRegionGrassObjectLayout, TESRegionObjectBaseLayout: GUESS(medium) STANDIN
// value08, value10: GUESS(low); each represents a separately observed eight-byte slot.
#pragma once
#include <cstddef>
namespace ResearchLayouts {
class TESRegionObjectBaseLayout {
public:
    virtual ~TESRegionObjectBaseLayout();
};
static_assert(sizeof(TESRegionObjectBaseLayout) == 8, "target sized-delete argument");
}
