// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// CombatBehaviorContextMagic: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function8b47f0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Provider8b47f0, Thread8b47f0, Context8b47f0, magicThread8b47f0: GUESS(low) STANDIN; magic behavior thread context
struct Provider8b47f0 {
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Copy(void*,void*);
};
struct Context8b47f0 { std::uint8_t unknown00[0x20]; void* value; };
struct Thread8b47f0 { std::uint8_t unknown00[0x158]; Context8b47f0* context; };
extern __declspec(thread) Thread8b47f0* magicThread8b47f0;

class CombatBehaviorContextMagic
{
public:
    std::uint8_t unknown00[0x10];
    Provider8b47f0* provider;

    void* Function8b47f0(void* output);
};
