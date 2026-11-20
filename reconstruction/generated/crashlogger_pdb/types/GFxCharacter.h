// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxCharacter; size 0x98
#pragma once

#include "Cxform.h"
#include "GFxLogBase_RE__GFxCharacter_45fe7224.h"
#include "GFxResourceID.h"
#include "GMatrix2D.h"
#include "GRefCountBaseWeakSupport_RE__GFxCharacter_322_28c5d268.h"
struct GFxSprite;
struct GFxCharacter {
    GRefCountBaseWeakSupport_RE__GFxCharacter_322_28c5d268 _base;
    GFxLogBase_RE__GFxCharacter_45fe7224 _base_GFxLogBase_RE_GFxCharacter_;
    GFxResourceID resourceID;
    unsigned int pad24;
    long long createdFrame;
    GFxSprite* parentClip;
    Cxform colorTransform;
    GMatrix2D matrix;
    unsigned long long unk70;
    unsigned long long unk78;
    unsigned long long unk80;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned short unk94;
    unsigned short unk96;
};
static_assert(sizeof(GFxCharacter) == 152, "GFxCharacter layout differs from the PDB");
