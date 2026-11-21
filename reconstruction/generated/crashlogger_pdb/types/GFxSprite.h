// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxSprite; size 0x350
#pragma once

#include "GASEnvironment.h"
#include "GArray_void_54131c0e.h"
#include "GFxASCharacter.h"
struct GASMovieClipObject;
struct GFxMovieRoot;
struct GFxSpriteDef;
struct GFxSprite {
    GFxASCharacter _base;
    GFxSpriteDef* spriteDef;
    GFxMovieRoot* movieRoot;
    unsigned long long unk120[5];
    unsigned int unk148;
    unsigned int currentFrame;
    GArray_void_54131c0e unk150;
    GASEnvironment unk168;
    unsigned long long unk308;
    unsigned long long unk310;
    GASMovieClipObject* movieClip;
    unsigned long long unk320;
    unsigned long long unk328;
    unsigned long long unk330;
    unsigned long long unk338;
    unsigned long long unk340;
    unsigned char unk348;
    unsigned char unk349;
    unsigned char unk34A;
    unsigned char unk34B;
    unsigned int unk34C;
};
static_assert(sizeof(GFxSprite) == 848, "GFxSprite layout differs from the PDB");
