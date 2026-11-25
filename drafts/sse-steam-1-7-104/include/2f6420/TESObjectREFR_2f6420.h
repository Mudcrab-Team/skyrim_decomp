// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; observed layout and labelled community declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, LOADED_REF_DATA, loadedData, AddChange: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e8, MIT)
// changeRecorded, TESObjectREFR::Function2f6420, Slot0, Slot1, Slot2, Slot3, Slot4, Slot5, Slot6, Slot7, Slot8, Slot9: STANDIN GUESS(low)

#pragma once
#include <cstdint>

struct LOADED_REF_DATA
{
    std::uint8_t prefix00[0x28];
    std::uint16_t reservedFlags : 4;
    std::uint16_t changeRecorded : 1;
    std::uint16_t remainingFlags : 11;
};

class TESObjectREFR
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual bool AddChange(std::uint32_t changeFlags);
    bool Function2f6420();
    std::uint8_t prefix08[0x60];
    LOADED_REF_DATA* loadedData;
};
