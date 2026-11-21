// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxMovieRoot; size 0x2bf0
#pragma once

#include "AlignType.h"
#include "Flag_a4a94b8a.h"
#include "GColor.h"
#include "GFxActionPriority.h"
#include "GFxFocusGroupDescr.h"
#include "GFxKeyboardState.h"
#include "GFxMouseState.h"
#include "GFxMovieView.h"
#include "GRect_float_808f464e.h"
#include "GViewport.h"
#include "ScaleModeType.h"
struct GASGlobalContext;
struct GFxMovieDef;
struct GFxSprite;
struct GMatrix3D;
struct GMemoryHeap;
struct MemoryContextImpl;
struct GFxMovieRoot {
    GFxMovieView _base;
    unsigned char undefined_18[1];
    GFxActionPriority _base_GFxActionPriority;
    unsigned char undefined_1a[6];
    unsigned long long unk0020;
    MemoryContextImpl* memoryContext;
    unsigned long long unk0030;
    GMemoryHeap* heap;
    void* levels;
    unsigned long long levelCount;
    unsigned long long unk0050;
    GFxSprite* timeline;
    GFxMovieDef* movieDef;
    unsigned long long unk0068;
    unsigned long long unk0070;
    GViewport unk0078;
    unsigned long long unk00B0;
    unsigned long long unk00B8;
    ScaleModeType viewScaleMode;
    AlignType viewAlignment;
    GRect_float_808f464e visibleFrameRect;
    GRect_float_808f464e safeRect;
    unsigned long long unk00E8;
    unsigned long long unk00F0;
    unsigned long long unk00F8;
    GMatrix3D* perspective3D;
    void* view3D;
    float mouseNdc[2];
    unsigned long long unk0118[273];
    GColor backgroundColor;
    unsigned int unk09A4;
    GFxMouseState mouseStates[4];
    unsigned int mouseCursorCount;
    unsigned int controllerCount;
    void* userData;
    unsigned long long unk0A78;
    GFxKeyboardState keyboardState;
    unsigned long long unk1108[627];
    GASGlobalContext* globalContext;
    unsigned long long unk24A8[39];
    Flag_a4a94b8a flags;
    unsigned int unk25E4;
    void** topmostLevelChars;
    unsigned long long topmostLevelCount;
    unsigned char undefined_25f8[80];
    GFxFocusGroupDescr focusGroups[16];
    unsigned int focusGroupCount;
    unsigned char controllerGroups[16];
    unsigned int unk2B54;
    unsigned long long unk2B58[18];
};
static_assert(sizeof(GFxMovieRoot) == 11248, "GFxMovieRoot layout differs from the PDB");
