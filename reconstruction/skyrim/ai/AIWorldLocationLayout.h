// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// AIWorldLocationLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// IAIWorldLocation, BGSAIWorldLocation: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// AIWorldPointLayout: GUESS(medium) STANDIN
// x, y, z: GUESS(medium); separate floating-point accesses and twelve-byte position transfers.
struct AIWorldPointLayout { float x; float y; float z; };
class AIWorldLocationLayout { public: virtual ~AIWorldLocationLayout(); };
static_assert(sizeof(AIWorldLocationLayout)==8,"own base sized delete");
static_assert(sizeof(AIWorldPointLayout)==12,"three separately accessed floats");
}
