// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// hkPrismaticConstraintCinfo, hkConstraintCinfo, hkSerializableCinfo: EXE_RTTI
// hkSerializableCinfo: STANDIN EXE_RTTI; only the members and destructors the function needs
// hkConstraintCinfo::SetConstraintData, hkpConstraintData: GUESS(low); releases the constraint data the info holds
#pragma once

class hkpConstraintData;

class hkSerializableCinfo
{
public:
    hkSerializableCinfo();

    char unk00[8];
};

struct hkConstraintCinfo : public hkSerializableCinfo
{
public:
    hkConstraintCinfo();
    virtual ~hkConstraintCinfo()
    {
        SetConstraintData(nullptr);
    }
    void SetConstraintData(hkpConstraintData* a_data);
};

struct hkPrismaticConstraintCinfo : public hkConstraintCinfo
{
public:
    hkPrismaticConstraintCinfo();

    char unk10[0x18];
};
static_assert(sizeof(hkPrismaticConstraintCinfo) == 0x28, "hkPrismaticConstraintCinfo size from the deleting destructor");
