// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// AIWorldPointRadiusLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// BGSAIWorldLocationPointRadius: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
#include "AIWorldLocationLayout.h"
namespace ResearchLayouts {
// point, space18, cell20, radius28, value2c, flag30, flag31: GUESS(medium) STANDIN; physical fields, meanings unverified.
class AIWorldPointRadiusLayout : public AIWorldLocationLayout { public: ~AIWorldPointRadiusLayout();
    AIWorldPointLayout point;
    void* space18;
    void* cell20;
    float radius28;
    float value2c;
    std::uint8_t flag30;
    std::uint8_t flag31;
};
static_assert(sizeof(AIWorldPointRadiusLayout)==56,"represented size");
static_assert(offsetof(AIWorldPointRadiusLayout,point)==8,"observed field offset");
static_assert(offsetof(AIWorldPointRadiusLayout,space18)==24,"observed field offset");
static_assert(offsetof(AIWorldPointRadiusLayout,cell20)==32,"observed field offset");
static_assert(offsetof(AIWorldPointRadiusLayout,radius28)==40,"observed field offset");
static_assert(offsetof(AIWorldPointRadiusLayout,value2c)==44,"observed field offset");
static_assert(offsetof(AIWorldPointRadiusLayout,flag30)==48,"observed field offset");
static_assert(offsetof(AIWorldPointRadiusLayout,flag31)==49,"observed field offset");
}
