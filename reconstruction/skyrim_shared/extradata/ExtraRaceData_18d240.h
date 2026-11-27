// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraRaceData: EXE_RTTI
// BSExtraData, BSExtraData::next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraRaceData::~ExtraRaceData, RaceDataRef, ExtraRaceData::raceData: GUESS(low) STANDIN
// ExtraRaceData::ctor: GUESS(low); CrashLogger PDB (59818@2026.10.24) lists ctor at 0x18d240, but the body decrements raceData refcount and deletes it
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
    ~ExtraRaceData() override;

    RaceDataRef* raceData;
};
static_assert(offsetof(ExtraRaceData, raceData) == 0x10, "ExtraRaceData::raceData offset");
static_assert(sizeof(ExtraRaceData) == 0x18, "ExtraRaceData size");
