// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSMasterParticleSystem, NiParticles, NiTimeController, NiRTTI, GetRTTI, controllers, next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsMasterParticleSystem: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
#pragma once

#include <cstdint>
#include <cstddef>

class NiRTTI;

// NiTimeController: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slots and member used here
class NiTimeController
{
public:
    // Unk_00, Unk_01: GUESS(low); placeholders for the first two NiObject slots
    virtual void          Unk_00();
    virtual void          Unk_01();
    virtual const NiRTTI* GetRTTI() const;  // 02

    std::uint8_t      pad08[0x38];  // 08
    NiTimeController* next;         // 40
};
static_assert(offsetof(NiTimeController, next) == 0x40, "next offset");

// NiParticles: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the controller list of its NiObjectNET base
class NiParticles
{
public:
    std::uint8_t      pad00[0x18];  // 00
    NiTimeController* controllers;  // 18
};

// g_masterParticleControllerRTTI: GUESS(low); the run-time type of the controller that marks a master particle system
extern const NiRTTI g_masterParticleControllerRTTI;

class BSMasterParticleSystem
{
public:
    static bool IsMasterParticleSystem(NiParticles* a_particles);  // compared: 0xffbcf0
};
