// Source exposure: binary-analysis
// HeapReleaseInterface, heap: GUESS(low) STANDIN; shared allocation-release dispatch
#pragma once
class HeapReleaseInterface {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Free(void*);
};
extern HeapReleaseInterface* heap;
