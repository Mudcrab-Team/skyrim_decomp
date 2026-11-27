// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4387f0 BSFaceGenMorphDataHair::BSFaceGenMorphDataHair
// Adapted bodies: BSFaceGenMorphDataHair::BSFaceGenMorphDataHair from fo4-private@1b765c70 src/Shared/FaceGen/BSFaceGenMorphData.cpp:117 (see the header)
#include "BSFaceGenMorphDataHair_4387f0.h"

BSFaceGenMorphDataHair::BSFaceGenMorphDataHair(const FffTriFileDataS& a_faceGenTri)
    : BSFaceGenMorphData(a_faceGenTri)
{
    uiHairMorphIndex = a_faceGenTri.diffMorphList.iSize > 0 ? 0 : 255;
}
