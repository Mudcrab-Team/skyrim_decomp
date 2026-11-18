// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// AIWorldRefRadiusLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// BGSAIWorldLocationRefRadius: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
#include "AIWorldLocationLayout.h"
namespace ResearchLayouts {
// handle08, radius0c, value10, value14, flag18: GUESS(medium) STANDIN; physical fields, meanings unverified.
class AIWorldRefRadiusLayout : public AIWorldLocationLayout { public: ~AIWorldRefRadiusLayout();
    std::uint32_t handle08;
    float radius0c;
    float value10;
    float value14;
    std::uint8_t flag18;
};
static_assert(sizeof(AIWorldRefRadiusLayout)==32,"represented size");
static_assert(offsetof(AIWorldRefRadiusLayout,handle08)==8,"observed field offset");
static_assert(offsetof(AIWorldRefRadiusLayout,radius0c)==12,"observed field offset");
static_assert(offsetof(AIWorldRefRadiusLayout,value10)==16,"observed field offset");
static_assert(offsetof(AIWorldRefRadiusLayout,value14)==20,"observed field offset");
static_assert(offsetof(AIWorldRefRadiusLayout,flag18)==24,"observed field offset");
}
