// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectCELL.cpp:2764
// TESObjectCELL, TESObjectCELL::GetLand, TESObjectCELL::GetLandHeight, TESObjectLAND, TESObjectLAND::GetLandHeight, NiPoint3: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to the members the body uses
#pragma once

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class TESObjectLAND
{
public:
    bool GetLandHeight(const NiPoint3& arPos, float& arHeight);
};

class TESObjectCELL
{
public:
    TESObjectLAND* GetLand();
    bool GetLandHeight(const NiPoint3& arPos, float& arHeight);
};
