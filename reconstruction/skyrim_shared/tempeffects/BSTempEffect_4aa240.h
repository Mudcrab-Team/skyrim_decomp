// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSTempEffect, TESObjectCELL, NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTempEffectBase, unk08, unk40: GUESS(low)
// BSTempEffectDebris::debris3D, BSTempEffectDebris::debrisFileName: CRASHLOGGER_PDB(59818@2026.10.24); corresponding names in this stand-in
#pragma once

#include <cstdint>

class TESObjectCELL;

// NiRefObject::IncRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared on the minimal object view.
class NiAVObject
{
public:
    void IncRefCount();
};

template <class T>
class NiPointer
{
public:
    explicit NiPointer(T* object) : _ptr(object)
    {
        if (_ptr) {
            _ptr->IncRefCount();
        }
    }

    ~NiPointer();

private:
    // NiPointer::_ptr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    T* _ptr;
};

// BSTempEffectBase: STANDIN GUESS(low); renamed base view of BSTempEffect.
class BSTempEffectBase
{
public:
    BSTempEffectBase(TESObjectCELL* cell, float lifetime);
    virtual ~BSTempEffectBase();

private:
    std::uint8_t unk08[0x28];
};

class BSTempEffect : public BSTempEffectBase
{
public:
    BSTempEffect();
    ~BSTempEffect() override;

private:
    NiPointer<NiAVObject> debris3D;
    const char* debrisFileName;
    std::uint16_t unk40;
};
