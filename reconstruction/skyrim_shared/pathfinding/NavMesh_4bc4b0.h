// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NavMesh: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function4bc4b0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Point4bc4b0, Data4bc4b0, Transform4bc4b0: GUESS(low) STANDIN; navigation vertex transforms
struct Point4bc4b0 { float x; float y; float z; };
struct Data4bc4b0 { std::uint64_t unknown00; void Update(); };
struct Transform4bc4b0 { float rotation[9]; Point4bc4b0 translation; float scale; void Apply(const Point4bc4b0*, unsigned, const Point4bc4b0*, Point4bc4b0*); };

class NavMesh
{
public:
    std::uint8_t unknown00[0x28];
    Data4bc4b0 data;
    std::uint8_t unknown30[8];
    Point4bc4b0* vertices;
    std::uint64_t unknown40;
    unsigned count;

    void Function4bc4b0(Transform4bc4b0* transform);
};
