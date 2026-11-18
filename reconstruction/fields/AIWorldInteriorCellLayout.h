// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// AIWorldInteriorCellLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// BGSAIWorldLocationInteriorCell: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
#include "AIWorldLocationLayout.h"
namespace ResearchLayouts {
// cell08, point: GUESS(medium) STANDIN; physical fields, meanings unverified.
class AIWorldInteriorCellLayout : public AIWorldLocationLayout { public: ~AIWorldInteriorCellLayout();
    void* cell08;
    AIWorldPointLayout point;
};
static_assert(sizeof(AIWorldInteriorCellLayout)==32,"represented size");
static_assert(offsetof(AIWorldInteriorCellLayout,cell08)==8,"observed field offset");
static_assert(offsetof(AIWorldInteriorCellLayout,point)==16,"observed field offset");
}
