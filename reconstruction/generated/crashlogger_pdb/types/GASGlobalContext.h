// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GASGlobalContext; size 0x568
#pragma once

#include "GASStringBuiltinManager.h"
#include "GRefCountBaseNTS_RE__GASGlobalContext_323_79b0d871.h"
struct GASGlobalObject;
struct GFxMovieRoot;
struct GMemoryHeap;
struct GASGlobalContext {
    GRefCountBaseNTS_RE__GASGlobalContext_323_79b0d871 _base;
    GASStringBuiltinManager _base_GASStringBuiltinManager;
    unsigned long long unk500;
    unsigned long long unk508;
    unsigned long long unk510;
    GFxMovieRoot* unk518;
    GMemoryHeap* heap;
    unsigned long long unk528;
    unsigned long long unk530;
    unsigned long long unk538;
    unsigned long long unk540;
    unsigned long long unk548;
    GASGlobalObject* globalObject;
    unsigned long long unk558;
    unsigned long long unk560;
};
static_assert(sizeof(GASGlobalContext) == 1384, "GASGlobalContext layout differs from the PDB");
