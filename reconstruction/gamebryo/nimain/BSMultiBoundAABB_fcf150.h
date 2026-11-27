// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSMultiBoundAABB, center, size: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GetBoundingSphere, pad00, unk28: GUESS(low); stand-in class view, members named by offset only
#pragma once
#include <cstdint>

class BSMultiBoundAABB
{
public:
    void GetBoundingSphere(float* a_sphere) const;  // compared: 0xfcf150

    std::uint8_t pad00[0x1C];  // 00
    float center[3];           // 1C
    float unk28;               // 28
    float size[3];          // 2C
};
