// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NavMesh, NavMesh::IsValidVertexLocation: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint34bdd00, gMaxVertexCoord: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" __declspec(dllimport) int __cdecl _finite(double a_val);

struct NiPoint34bdd00
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint34bdd00) == 0x0C, "NiPoint34bdd00 size");

extern const float gMaxVertexCoord;

class NavMesh
{
public:
    static bool IsValidVertexLocation(const NiPoint34bdd00& a_loc);  // compared: 0x4bdd00
};
