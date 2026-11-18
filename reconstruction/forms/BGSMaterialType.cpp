// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x322250 BGSMaterialType::ClearData
#include "BGSMaterialType.h"
void BGSMaterialType::ClearData() {
    materialName=BSFixedString(nullptr);
    parent=nullptr;
    materialKind=0;
    flags=0;
    color=defaultMaterialColor;
    buoyancy=1.0f;
    impact=nullptr;
}
