// Source exposure: binary-analysis (pinned-image observations); sibling game-code declarations inspected.
// Code origin: original; names and dispatch signatures are conservative stand-ins.
// SPDX-License-Identifier: CC0-1.0
// TESRegionDataGrass, Function250390, DispatchTarget, LookupTarget, Dispatch, Slot0, Slot1, Slot2, Slot3, Slot4, Slot5: GUESS(low) STANDIN; opaque virtual interfaces at observed slots.
#pragma once

class DispatchTarget {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Dispatch(void* argument, unsigned int mode);
};
class TESRegionDataGrass {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual DispatchTarget* LookupTarget();
    DispatchTarget* Function250390(void* argument);
};
