// Source exposure: mixed (pinned community declarations and private target analysis).
// Code origin: original handwritten reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectWEAP, TESObjectWEAP::Data, TESObjectWEAP::weaponData, TESObjectWEAP::Data::animationType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Setting, Setting::Data, Setting::data, Setting::Data::f: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectWEAP::Function28c410, g_weaponTypeSettings, unk000, unobservedPrefix, storage: GUESS(low); settings table purpose is unknown
#pragma once

#include <cstdint>
#include <cstddef>

class Setting
{
public:
    virtual ~Setting();
    union Data {
        float f;
        std::uint64_t storage;
    };
    Data data;
};

extern Setting* g_weaponTypeSettings[];

class TESObjectWEAP
{
public:
    struct Data {
        char unobservedPrefix[0x35];
        // The target indexes through a signed byte; NG uses an unsigned byte.
        std::int8_t animationType;
    };
    char unk000[0x168];
    Data weaponData;

    float Function28c410() const;
};

static_assert(offsetof(TESObjectWEAP, weaponData) + offsetof(TESObjectWEAP::Data, animationType) == 0x19d, "weapon type offset");
