// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from binary analysis; names from CommonLibSSE-NG (MIT) and powerof3/CommonLibSSE (GPL-3.0); no external implementation body is copied Stamped as a twin of matched 0x2bb150 (skyrim_shared/world/TESObjectCELL): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// The names CreateDuplicateForm and IsParentForm come from powerof3/CommonLibSSE 654e55f, which is GPL-3.0; that licence applies to those declarations.
// at CommonLibSSE-NG b93280e, powerof3/CommonLibSSE 654e55f and momusdigital/fnv_decomp 91e1b6e8.
// BGSEncounterZone, BGSLocation, bhkWorld, TESWorldSpace, LOADED_CELL_DATA, EXTERIOR_DATA, INTERIOR_DATA, ExtraDataList, BSSpinLock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function1e6450, Owner1e6450: GUESS(low) STANDIN
// GetbhkWorld, GetCoordinates, GetLocation, GetOwner, EnterReferenceListLock, ExitReferenceListLock, GetEncounterZone, TESForm, Owner1e6450, CellData, exterior, interior, CreateDuplicateForm, IsParentForm, GetWorldSpaceOfExteriorCell, Function2bf550, Function2c5c70, Function2bf600, Function224a90, Function2bf580, Function2bf5c0: GUESS(low) STANDIN
#pragma once
#include "TESObjectCELL.h"

// compared functions read; the layout is the image's (59 virtual slots, size 0x148).
class Owner1e6450 : public TESForm {
public:
    union CellData {
        EXTERIOR_DATA* exterior;  // XCLC
        INTERIOR_DATA* interior;  // XCLL
    };

    void               EnterReferenceListLock();
    void               ExitReferenceListLock();
    bhkWorld*          GetbhkWorld() const;
    // EXTERIOR_DATA* GetCoordinates(), but the function at RVA 0x2bc660 writes the cell's two
    // coordinates through two reference parameters, so the name is kept with that signature.
    void               GetCoordinates(std::int32_t& a_x, std::int32_t& a_y);
    BGSEncounterZone*  GetEncounterZone() const;
    BGSLocation*       GetLocation() const;
    TESForm*           GetOwner();
    TESForm*           CreateDuplicateForm(bool a_createEditorID, void* a_arg2);
    bool               IsParentForm();
    TESWorldSpace*     GetWorldSpaceOfExteriorCell();
    void               Function1e6450(bool a_set);
    bool               Function2bf600() const;
    void               Function2bf550(bool a_set);
    void               Function2c5c70(bool a_set);
    static bool        Function224a90(TESForm* a_form, TESForm*& a_outA, TESForm*& a_outB);
    void               Function2bf580(bool a_set);
    void               Function2bf5c0(bool a_set);

    std::uint8_t       unk20[0x20];        // 20 - TESFullName base
    std::uint16_t      cellFlags;          // 40
    std::uint16_t      cellGameFlags;      // 42
    std::uint8_t       unk44[4];           // 44
    ExtraDataList      extraList;          // 48
    std::uint8_t       unk60[8];           // 60
    CellData           cellData;           // 68
    std::uint8_t       unk70[0xB0];        // 70
    BSSpinLock         spinLock;           // 120
    TESWorldSpace*     worldSpace;         // 128
    LOADED_CELL_DATA*  loadedData;         // 130
    void*              lightingTemplate;   // 138
    std::uint64_t      unk140;             // 140
};
static_assert(sizeof(Owner1e6450) == 0x148, "layout");
