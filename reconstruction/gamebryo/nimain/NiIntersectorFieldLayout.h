// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// NiIntersectorFieldLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// NiIntersector: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// IntersectorPointLayout: GUESS(medium) STANDIN
// x, y, z: GUESS(low); separately initialized scalar components.
struct IntersectorPointLayout { float x; float y; float z; };
}
namespace ResearchLayouts {
// value08, value0c, value10, value14, iterations18, state1c, time20, point24, point30: GUESS(medium) STANDIN; physical fields, meanings unverified.
class NiIntersectorFieldLayout { public: virtual ~NiIntersectorFieldLayout();
    float value08;
    float value0c;
    float value10;
    float value14;
    std::int32_t iterations18;
    std::int32_t state1c;
    float time20;
    IntersectorPointLayout point24;
    IntersectorPointLayout point30;
};
static_assert(sizeof(NiIntersectorFieldLayout)==64,"represented size");
static_assert(offsetof(NiIntersectorFieldLayout,value08)==8,"observed field offset");
static_assert(offsetof(NiIntersectorFieldLayout,value0c)==12,"observed field offset");
static_assert(offsetof(NiIntersectorFieldLayout,value10)==16,"observed field offset");
static_assert(offsetof(NiIntersectorFieldLayout,value14)==20,"observed field offset");
static_assert(offsetof(NiIntersectorFieldLayout,iterations18)==24,"observed field offset");
static_assert(offsetof(NiIntersectorFieldLayout,state1c)==28,"observed field offset");
static_assert(offsetof(NiIntersectorFieldLayout,time20)==32,"observed field offset");
static_assert(offsetof(NiIntersectorFieldLayout,point24)==36,"observed field offset");
static_assert(offsetof(NiIntersectorFieldLayout,point30)==48,"observed field offset");
}
