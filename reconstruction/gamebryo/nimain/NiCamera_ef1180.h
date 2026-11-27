// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCamera, NiPoint3, WorldPtToScreenPt3, left, right, top, bottom: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Recipe: reconstruction/recipes/o2-fpfast.json
#pragma once

struct NiPoint3
{
    float x;
    float y;
    float z;
};

template <class T>
struct NiRect
{
    T left;
    T right;
    T top;
    T bottom;
};

class NiCamera
{
public:
    static bool WorldPtToScreenPt3(
        const float matrix[4][4],
        const NiRect<float>& port,
        const NiPoint3& in,
        float& xOut,
        float& yOut,
        float& zOut,
        float zeroTolerance);
};
