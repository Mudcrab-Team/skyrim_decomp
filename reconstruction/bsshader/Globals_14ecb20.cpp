// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: SetRectCenterAndHalfExtents.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshadermanager.cpp:448
// 0x14ecb20 SetRectCenterAndHalfExtents
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsshader/bsshadermanager.cpp:430
#include "Globals_14ecb20.h"

void SetRectCenterAndHalfExtents(tagRECT* apLoadedRect)
{
    int lhalfHeight;
    int lhalfWidth;
    lhalfWidth = (apLoadedRect->right - apLoadedRect->left) / 2;
    lhalfHeight = (apLoadedRect->top - apLoadedRect->bottom) / 2;
    Data011f95f4 = apLoadedRect->left + (float)lhalfWidth;
    Data011f95f8 = apLoadedRect->bottom + (float)lhalfHeight;
    Data011f95fc = (float)lhalfWidth;
    Data011f9600 = (float)lhalfHeight;
}
