// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original declarations inferred from the pinned listing, with names as labelled below
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// Source exposure: mixed (community declarations and binary analysis).
// NiMeshParticleSystem, NiParticleSystem, UpdateDownwardPass, UpdateSelectedDownwardPass, NiUpdateData, flags, time: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// savedTime, pad, TestBit: GUESS(low)
#pragma once
#include <cstdint>
struct NiUpdateData { float time; std::uint32_t flags; };
inline bool TestBit(std::uint32_t flags, unsigned bit) { return ((flags >> bit) & 1) != 0; }
class NiParticleSystem {
public:
    void UpdateSelectedDownwardPass(NiUpdateData&, std::uint32_t);
    unsigned char pad[0x198];
};
class NiMeshParticleSystem : public NiParticleSystem {
public:
    void UpdateDownwardPass(NiUpdateData&, std::uint32_t);
    float savedTime;
};
