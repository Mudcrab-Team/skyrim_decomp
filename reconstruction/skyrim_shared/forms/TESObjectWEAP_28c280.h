// Source exposure: mixed (pinned community declarations; private target observations).
// Code origin: original handwritten reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectWEAP, TESObjectWEAP::weaponData, TESObjectWEAP::Data, TESObjectWEAP::Data::flags, TESObjectWEAP::embeddedNode, BSFixedString, BSFixedString::_data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectWEAP::Function28c280, GetDefaultEmbeddedNode, defaultEmbeddedNode, unobservedPrefix, unobservedSuffix: GUESS(low); helper and data purposes inferred from use
#pragma once
#include <cstdint>
#include <cstddef>
struct BSFixedString { const char* _data; };
const BSFixedString& GetDefaultEmbeddedNode();
extern const BSFixedString defaultEmbeddedNode;
class TESObjectWEAP {
public:
    struct Data {
        std::uint8_t unobservedPrefix[0x36];
        std::uint8_t flags;
    };
    std::uint8_t unobservedPrefix[0x168];
    Data weaponData;
    std::uint8_t unobservedSuffix[0x210 - 0x168 - sizeof(Data)];
    BSFixedString embeddedNode;
    const BSFixedString& Function28c280() const;
};
static_assert(offsetof(TESObjectWEAP, weaponData) + offsetof(TESObjectWEAP::Data, flags) == 0x19e, "weapon flags offset");
static_assert(offsetof(TESObjectWEAP, embeddedNode) == 0x210, "embedded node offset");
