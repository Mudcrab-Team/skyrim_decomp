// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: original reconstruction from the pinned image and community declarations.
// Consulted (private, not in repo): decompiler control-flow hints.
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x7cf1e0 JumpAnimEventHandler::Handle
#include "JumpAnimEventHandler.h"
#include "skyrim_shared/actors/Actor.h"

// bhkCharacterController, hkpCharacterContext, context: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// hkpCharacterStateType, hkpCharacterStateTypes::hkpCharacterStateType::kSwimming: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Slot00 through Slot0E, GetSupport, unknown008, GetState, SetJumpHeight, jumpHeight, swimmingJumpMultiplier, IsMount: GUESS(low)
enum class hkpCharacterStateType : std::uint32_t { kSwimming = 5 };

class hkpCharacterContext {
public:
    hkpCharacterStateType GetState() const;
};

class bhkCharacterController {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void* GetSupport();

    std::uint64_t unknown008[0x3b];
    hkpCharacterContext context;

    void SetJumpHeight(float a_height);
};
static_assert(offsetof(bhkCharacterController, context) == 0x1e0, "bhkCharacterController::context offset");

extern float jumpHeight;
extern float swimmingJumpMultiplier;

static bool IsMount(Actor::BOOL_FLAGS a_flags)
{
    return ((static_cast<std::uint32_t>(a_flags) >> 1) & 1) != 0;
}

bool JumpAnimEventHandler::Handle(Actor* a_actor)
{
    auto* controller = a_actor->GetCharController();
    if (controller && controller->GetSupport() && !a_actor->IsOnMount()) {
        const auto height = jumpHeight;
        auto scaledHeight = a_actor->GetScale() * height;
        if (controller->context.GetState() == hkpCharacterStateType::kSwimming && !IsMount(a_actor->boolFlags)) {
            scaledHeight *= swimmingJumpMultiplier;
        }
        controller->SetJumpHeight(scaledHeight);
    }
    return true;
}
