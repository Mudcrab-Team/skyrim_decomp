// Code origin: original reconstruction from the pinned image and community declarations.
// Consulted (private, not in repo): decompiler control-flow hints.
// 0x7559f0 PlayerCharacter::SetAIDriven
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"PlayerCharacter","rationale":"vtable owner and slot; method spelling invented","slot":8},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Slot8 was synthesized from the bounded leaf template.
// PlayerCharacter: EXE_RTTI
// Slot8: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x75c2b0 PlayerCharacter::Slot8
#include "PlayerCharacter.h"
// Slot8: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t PlayerCharacter::Slot8() const
{
    return 0x1;
}

// MovementControllerNPC, Unk_0C, Unk_0D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_01, Unk_02, Unk_03, Unk_04, Unk_05, Unk_06, Unk_07, Unk_08, Unk_09, Unk_0A, Unk_0B: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); earlier slots.
class MovementControllerNPC {
public:
    virtual ~MovementControllerNPC();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
};

// AIProcess, TESPackage, PACKAGE_PROCEDURE_TYPE, kVampireFeed, currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// playerFlags, PlayerCamera: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetCurrentPackage, ClearVampireFeedCamera, playerCamera, PackageTypeWindow, packageType: GUESS(low); package and camera state.
enum class PACKAGE_PROCEDURE_TYPE : std::uint8_t { kVampireFeed = 37 };
struct PackageTypeWindow {
    PACKAGE_PROCEDURE_TYPE packageType;
};
class TESPackage;
class AIProcess {
public:
    TESPackage* GetCurrentPackage() const;
};

// PlayerPackageFlags: GUESS(low); view of byte 2 of the community PlayerFlags layout.
// PlayerCharacter::PlayerFlags::unk2_0, ::aiControlledToPos, ::aiControlledFromPos, ::aiControlledPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PlayerCharacter::PlayerFlags::returnToLastKnownGoodPosition, ::isBeingChased, ::unk2_6, ::unk2_7: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct PlayerPackageFlags {
    bool unk2_0 : 1;
    bool aiControlledToPos : 1;
    bool aiControlledFromPos : 1;
    bool aiControlledPackage : 1;
    bool returnToLastKnownGoodPosition : 1;
    bool isBeingChased : 1;
    bool unk2_6 : 1;
    bool unk2_7 : 1;
};
static_assert(sizeof(PlayerPackageFlags) == 1, "AI package flags use one byte");

class PlayerCamera {
public:
    void ClearVampireFeedCamera();
};
extern PlayerCamera* playerCamera;

void PlayerCharacter::SetAIDriven(bool a_driven)
{
    auto* controller = GetMovementController();
    if (a_driven) {
        controller->Unk_0C();
    } else {
        controller->Unk_0D();
        auto* currentProcess = *reinterpret_cast<AIProcess**>(reinterpret_cast<char*>(this) + 0xf8);  // 0xf8 currentProcess
        const auto* package = currentProcess->GetCurrentPackage();
        if (package) {
            const auto& type = *reinterpret_cast<const PackageTypeWindow*>(reinterpret_cast<const char*>(package) + 0x24);  // 0x24 packageType
            if (type.packageType == PACKAGE_PROCEDURE_TYPE::kVampireFeed) {
                playerCamera->ClearVampireFeedCamera();
            }
        }
    }
    auto& playerFlags = *reinterpret_cast<PlayerPackageFlags*>(reinterpret_cast<char*>(this) + 0xbea);  // 0xbea playerFlags byte 2
    playerFlags.aiControlledPackage = a_driven;
}
