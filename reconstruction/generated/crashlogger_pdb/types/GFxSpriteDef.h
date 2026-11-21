// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxSpriteDef; size 0x60
#pragma once

#include "GArrayLH_RE__GFxTimelineDef__ExecuteTagList_e62d653d.h"
#include "GFxTimelineIODef.h"
#include "GStringHash_int_70308b3a.h"
struct GFxMovieDataDef;
struct GFxSpriteDef {
    GFxTimelineIODef _base;
    GFxMovieDataDef* movieData;
    GStringHash_int_70308b3a frameLabels;
    int frameCount;
    int frameLoading;
    GArrayLH_RE__GFxTimelineDef__ExecuteTagList_e62d653d frames;
    void* unk50;
    unsigned char buttonState;
    unsigned char pad59;
    unsigned short pad5A;
    unsigned int pad5C;
};
static_assert(sizeof(GFxSpriteDef) == 96, "GFxSpriteDef layout differs from the PDB");
