// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BookMenu; size 0x98
#pragma once

#include "BSTArray_RE__BSScaleformExternalTexture_e936ab54.h"
#include "BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d.h"
#include "GPtr_RE__GFxMovieView_2d8822bd.h"
#include "IMenu_09c1ffe2.h"
#include "NiPointer_RE__BSGeometry_933f0714.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "SimpleAnimationGraphManagerHolder.h"
struct NiSourceTexture_cc202fc8;
struct BookMenu {
    IMenu_09c1ffe2 _base;
    SimpleAnimationGraphManagerHolder _base_SimpleAnimationGraphManagerHolder;
    BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d _base_BSTEventSink_RE_BSAnimationGraphEvent_;
    BSTArray_RE__BSScaleformExternalTexture_e936ab54 bookTextures;
    GPtr_RE__GFxMovieView_2d8822bd book;
    NiPointer_RE__NiAVObject_9e3aa701 bookModel;
    unsigned int numRenderTargets;
    unsigned int pad7C;
    NiSourceTexture_cc202fc8* pageTexture;
    NiPointer_RE__BSGeometry_933f0714 pageTextGeo;
    unsigned short unk90;
    unsigned short startAnimating;
    bool closeMenu;
    bool isNote;
    bool bookInitialized;
    unsigned char pad97;
};
static_assert(sizeof(BookMenu) == 152, "BookMenu layout differs from the PDB");
