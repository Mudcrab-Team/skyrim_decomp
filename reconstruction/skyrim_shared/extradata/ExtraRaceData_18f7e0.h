// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRaceData: EXE_RTTI
// ExtraRaceData::~ExtraRaceData: CRASHLOGGER_PDB(59818@2026.10.24)
// BSExtraData, BSExtraData::next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RaceDataRef, ExtraRaceData::raceData: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class BSExtraData
{
public:
    virtual ~BSExtraData() {}

    BSExtraData* next;
};
static_assert(sizeof(BSExtraData) == 0x10, "BSExtraData size");

class RaceDataRef
{
public:
    virtual ~RaceDataRef();

    long refCount;
};
static_assert(offsetof(RaceDataRef, refCount) == 0x08, "RaceDataRef::refCount offset");

class ExtraRaceData : public BSExtraData
{
public:
    ExtraRaceData();
    ~ExtraRaceData() override
    {
        RaceDataRef* ptr = raceData;
        // intrusive ref-count: atomic release of race data
        if (ptr && _InterlockedDecrement(&ptr->refCount) == 0) {
            delete ptr;
        }
    }

    RaceDataRef* raceData;
};
static_assert(offsetof(ExtraRaceData, raceData) == 0x10, "ExtraRaceData::raceData offset");
static_assert(sizeof(ExtraRaceData) == 0x18, "ExtraRaceData size");
