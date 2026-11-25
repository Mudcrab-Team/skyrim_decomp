// TESObjectLAND type declaration, build sse-steam-1-7-104.
//
// Exposure detail: (binary-analysis of the pinned image, community-headers).
// Source exposure: mixed
// Names and offsets follow CharmedBaryon/CommonLibSSE-NG b93280e (MIT): include/RE/T/TESObjectLAND.h.
// SetAltered follows the shape of the sibling's TESObjectLAND::SetAltered_00539010 (base call, then
// propagate to the owner when set). Layouts of the stand-ins are not claimed.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesland_od_variant.cpp:928
// TESObjectLAND, TESObjectLAND::CreateDuplicateForm, ::SetAltered, ::parentCell, ::data, ::pad2C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectLAND::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; a 4-byte block here, NG declares OBJ_LAND
// TESObjectLAND::unk38: GUESS(low); stands for queuedTextures and loadedData
// TESChildCell, TESChildCell::GetSaveParentCell: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the TESForm base is needed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once

#include <cstdint>
#include <intrin.h>

#include "TESForm.h"

class TESObjectCELL : public TESForm {
};

class TESChildCell {
public:
    TESChildCell();
    // TESChildCell::~TESChildCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual ~TESChildCell() {}  // 00
    virtual TESObjectCELL* GetSaveParentCell();  // 01
};

// LandRefObject, LandTextureOwner, object, references: GUESS(low); represented queued reference ownership.
struct LandRefObject {
    virtual ~LandRefObject();
    volatile long references;
};
struct LandTextureOwner {
    ~LandTextureOwner() {
        auto* object = value;
        if (object && _InterlockedExchangeAdd(&object->references, -1) == 1) delete object;
    }
    LandRefObject* value;
};
// LoadedLandData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class LoadedLandData;
class TESObjectLAND : public TESForm, public TESChildCell {
public:
    // TESObjectLAND::TESObjectLAND, TESObjectLAND::ClearLand: GUESS(low); emission constructor and retained cleanup call.
    TESObjectLAND();
    void ClearLand();
    // TESObjectLAND::~TESObjectLAND: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    ~TESObjectLAND() override;
    TESForm* CreateDuplicateForm(bool a_createEditorID, void* a_arg2) override;  // 09
    void     SetAltered(bool a_set) override;                                    // 24

    std::uint32_t  data;        // 28
    std::uint32_t  pad2C;       // 2C
    TESObjectCELL* parentCell;  // 30
    // queuedTextures, loadedData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    LandTextureOwner queuedTextures;  // 38
    LoadedLandData* loadedData;       // 40
};
static_assert(sizeof(TESObjectLAND) == 0x48, "layout");
