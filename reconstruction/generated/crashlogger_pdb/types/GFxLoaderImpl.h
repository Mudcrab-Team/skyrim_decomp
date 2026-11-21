// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxLoaderImpl; size 0x78
#pragma once

#include "GFxLogBase_RE__GFxLoaderImpl_6ec95df8.h"
#include "GFxStateBag.h"
#include "GLock.h"
#include "GRefCountBase_RE__GFxLoaderImpl_2_bf8b42e2.h"
struct GFxStateBagImpl;
struct GFxLoaderImpl {
    GRefCountBase_RE__GFxLoaderImpl_2_bf8b42e2 _base;
    GFxStateBag _base_GFxStateBag;
    unsigned char undefined_18[8];
    GFxLogBase_RE__GFxLoaderImpl_6ec95df8 _base_GFxLogBase_RE_GFxLoaderImpl_;
    GFxStateBagImpl* stateBagImpl;
    unsigned long long pad30;
    void* pad38;
    void* pad40;
    GLock lock;
    unsigned char pad70;
    unsigned char pad71;
    unsigned short pad72;
    unsigned int pad74;
};
static_assert(sizeof(GFxLoaderImpl) == 120, "GFxLoaderImpl layout differs from the PDB");
