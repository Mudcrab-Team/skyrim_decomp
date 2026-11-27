// Source exposure: mixed (community headers; the pinned image listing; sibling decompilation shape).
// Code origin: adapted from the sibling decompilation; adapted bodies: BSLightingShaderMaterialFacegen::CopyMembers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00ba0000_o2.cpp:4100
// BSLightingShaderMaterialFacegen: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialFacegen::CopyMembers, tintTexture, detailTexture, subsurfaceTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>
#include "BSLightingShaderMaterialBase.h"

class BSLightingShaderMaterialFacegen : public BSLightingShaderMaterialBase
{
public:
    void CopyMembers(BSShaderMaterial* a_other) override;  // 02, compared: 0x1526950

    NiPointer<NiSourceTexture> tintTexture;        // A0
    NiPointer<NiSourceTexture> detailTexture;      // A8
    NiPointer<NiSourceTexture> subsurfaceTexture;  // B0
};
static_assert(sizeof(BSLightingShaderMaterialFacegen) == 0xB8, "BSLightingShaderMaterialFacegen size");
