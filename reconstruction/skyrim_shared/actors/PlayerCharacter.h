// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"PlayerCharacter","rationale":"vtable owner and slot; method spelling invented","slot":8},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// PlayerCharacter: EXE_RTTI
// Slot8: GUESS(low)
// Function75d390, Function5d2080, unknown98: GUESS(low)
// member, padding, Function1e6030, flags10: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstddef>
#include <cstdint>

// MagicTargetPrefix: STANDIN GUESS(low); invented prefix name for the MagicTarget-shaped receiver subobject at 0xa0, sized only.
// flags, postUpdateDispelList: GUESS(low); spellings follow NG's MagicTarget fields, the prefix above is invented.
struct MagicTargetPrefix
{
    const void*    vtable;               // 00
    void*          postUpdateDispelList;  // 08
    std::uint32_t  flags;                // 10
    std::uint32_t  unknown14;            // 14
};
static_assert(sizeof(MagicTargetPrefix) == 0x18, "MagicTargetPrefix size");

// PlayerCharacterManager, unknown160: GUESS(low); pointer global whose word at 0x160 is compared with zero.
struct PlayerCharacterManager
{
    std::uint8_t  pad00[0x160];  // 00
    std::uint32_t unknown160;    // 160
};
static_assert(offsetof(PlayerCharacterManager, unknown160) == 0x160, "manager word offset");

// g_playerCharacterManager: GUESS(low); the global at RVA 0x219e5c0.
extern PlayerCharacterManager* g_playerCharacterManager;
// Slot8: GUESS(low); method name inferred from vtable owner and slot
class PlayerCharacter
{
public:
    virtual std::uint8_t Slot8() const;
    void Function1e6030(bool a_set);

    std::uint32_t pad08;    // 08
    std::uint32_t pad0C;    // 0C
    std::uint32_t flags10;  // 10
    void Function75d390();

    std::uint8_t pad14[0x84];  // 14
    std::uint64_t unknown98;   // 98
    // magicTarget: GUESS(low); the target adds 0xa0 to the receiver and passes that address to the callee.
    MagicTargetPrefix magicTarget;  // a0
    std::uint8_t padB8[0x8f4 - 0xb8];  // b8
    // sleepSeconds: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG names the runtime word, the offset here is measured.
    std::uint32_t sleepSeconds;  // 8f4
};
static_assert(offsetof(PlayerCharacter, flags10) == 0x10, "flags offset");
static_assert(offsetof(PlayerCharacter, magicTarget) == 0xa0, "receiver subobject offset");
static_assert(offsetof(PlayerCharacter, sleepSeconds) == 0x8f4, "runtime word offset");
static_assert(sizeof(PlayerCharacter) == 0x8f8, "PlayerCharacter size");

// Function5d2080: GUESS(low); declared only, the target tail-jumps to RVA 0x5d2080.
void Function5d2080(MagicTargetPrefix* a_target, float a_value);
