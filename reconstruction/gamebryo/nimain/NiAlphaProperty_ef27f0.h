// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; represented declarations use the labelled sources below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAlphaProperty, NiProperty, NiCloningProcess, NiAlphaProperty::alphaFlags, NiAlphaProperty::alphaThreshold: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAlphaProperty::CopyMembers: CRASHLOGGER_PDB(59818@2026.10.24)
// NiProperty::CopyMembers, unknown: GUESS(low) STANDIN; observed base-copy boundary and unaccessed base extent.
#pragma once
#include <cstdint>
#include <cstddef>
class NiCloningProcess;
class NiProperty {
public:
    std::uint8_t unknown[0x30];
    void CopyMembers(NiProperty* destination, NiCloningProcess& cloning);
};
class NiAlphaProperty : public NiProperty {
public:
    std::uint16_t alphaFlags;
    std::uint8_t alphaThreshold;
    void CopyMembers(NiAlphaProperty* destination, NiCloningProcess& cloning); // compared: 0xef27f0
};
