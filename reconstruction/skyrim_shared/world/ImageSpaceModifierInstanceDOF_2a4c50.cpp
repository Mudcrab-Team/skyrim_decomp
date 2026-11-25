// Source exposure: mixed (community declarations, the cited sibling and the pinned image listing).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a4c50 ImageSpaceModifierInstanceDOF::PrintInfo
// Adapted bodies: ImageSpaceModifierInstanceDOF::PrintInfo follows momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/imagespacemodifierinstance.cpp
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/imagespacemodifierinstance.cpp:465
#include "ImageSpaceModifierInstanceDOF_2a4c50.h"

// Writes the three depth-of-field values the debug overlay shows.
void ImageSpaceModifierInstanceDOF::PrintInfo(char* a_dstBuf)
{
    sprintf_s(a_dstBuf, 0x800, "  DOF  Distance: %f  Range: %f  Str: %f", distance, range, strength);
}
