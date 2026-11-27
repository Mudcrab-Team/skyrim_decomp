// Source exposure: binary-analysis
// Unlock10104f0: GUESS(low) STANDIN; original owner is unknown
// Function10104f0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Mapped10104f0 { void* data; std::uint32_t rowPitch; std::uint32_t depthPitch; };
class Context10104f0 { public:
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
    virtual void Slot12();
    virtual void Slot13();
    virtual int Map(void*, std::uint32_t, std::uint32_t, std::uint32_t, Mapped10104f0*);
};
extern std::uint32_t resourceIndex;
extern void* resources[4];
extern void* fallbackResource;
extern void* currentResource;
extern Context10104f0* context;

class Unlock10104f0 {
public:
    static void** Function10104f0(void*, void*, void** out, std::uint32_t kind);
};
