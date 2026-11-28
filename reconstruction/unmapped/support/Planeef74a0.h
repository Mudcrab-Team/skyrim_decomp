// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Planeef74a0::Planeef74a0, treated as adapted: shaped like NiPlane::NiPlane in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/console/nipoint3.inl:58
// SPDX-License-Identifier: CC0-1.0
// Point3ef74a0, Planeef74a0: GUESS(low) STANDIN
#pragma once

struct Point3ef74a0
{
    Point3ef74a0() : x(0.0f), y(0.0f), z(0.0f) {}

    float x;  // 0x00
    float y;  // 0x04
    float z;  // 0x08
};

struct Planeef74a0
{
    Planeef74a0(const Point3ef74a0& a_normal, const Point3ef74a0& a_point);  // compared: 0xef74a0

    Point3ef74a0 normal;  // 0x00
    float constant;       // 0x0C
};
