// Source exposure: mixed
// names: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); kind-of helper adapted
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1382
// Unlock2fa190: GUESS(low) STANDIN; original owner is unknown
// Function2fa190: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct Type2fa190 { const char* name; const Type2fa190* base; };
extern Type2fa190 rigidBodyType;
class Body2fa190 { public: virtual ~Body2fa190(); virtual void Slot1(); virtual const Type2fa190* GetRTTI();
    bool IsKindOfType(const Type2fa190* type) {
        auto* current = GetRTTI();
        while (current) { if (current == type) return true; current = current->base; }
        return false;
    } };

class Unlock2fa190 {
public:
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    Body2fa190* object;
    Body2fa190* Function2fa190();
};
