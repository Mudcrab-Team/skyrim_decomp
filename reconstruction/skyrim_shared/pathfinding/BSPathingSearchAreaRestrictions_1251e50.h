// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPathingSearchAreaRestrictions, Read, center, radius: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSPathingReadStream1251e50: GUESS(low) STANDIN
#pragma once

class BSPathingReadStream1251e50
{
public:
    virtual ~BSPathingReadStream1251e50();
    virtual void ReadFloat(float* out);  // 08
};

class NiPoint3
{
public:
    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

class BSPathingSearchAreaRestrictions
{
public:
    void Read(BSPathingReadStream1251e50* stream);

    NiPoint3 center;  // 00
    float    radius;  // 0C
};
static_assert(sizeof(BSPathingSearchAreaRestrictions) == 0x10, "BSPathingSearchAreaRestrictions size");
