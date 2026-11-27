// Source exposure: mixed (target observations; permitted sibling naming hints).
// Code origin: original; observed layout and labelled names
// SPDX-License-Identifier: CC0-1.0
// TESObjectWEAP, TESObjectWEAP::GetFireNode, NiAVObject::LookupBoneNodeByName: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString, NiAVObject: GUESS(low) STANDIN
// GetDefaultFireNodeName, primaryFireNodeName, fallbackFireNodeName, flags, fireNodeName: GUESS(low) STANDIN
// TESObjectWEAP field offsets: OBSERVED
#pragma once
#include <cstdint>
#include <cstddef>
struct BSFixedString { const char* data; };
const BSFixedString& GetDefaultFireNodeName();
extern BSFixedString primaryFireNodeName;
extern BSFixedString fallbackFireNodeName;
class NiAVObject
{
public:
    NiAVObject* LookupBoneNodeByName(const BSFixedString& name, bool defer);
};
class TESObjectWEAP
{
public:
    NiAVObject* GetFireNode(NiAVObject* node) const;
    std::uint8_t unknown0[0x19e];
    std::uint8_t flags;
    std::uint8_t unknown19f[0x71];
    BSFixedString fireNodeName;
};
static_assert(offsetof(TESObjectWEAP, fireNodeName) == 0x210, "observed fire node name offset");
