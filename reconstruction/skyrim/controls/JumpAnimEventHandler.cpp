// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: original reconstruction from the pinned image and community declarations.
// Consulted (private, not in repo): decompiler control-flow hints.
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x7cf1e0 JumpAnimEventHandler::Handle
#include "JumpAnimEventHandler.h"
#include "skyrim_shared/actors/Actor.h"

// bhkCharacterController, hkpCharacterContext, context, hkpCharacterStateType, kSwimming: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared in Actor.h
// Unk_0F, GetState, SetJumpHeight, jumpHeight, swimmingJumpMultiplier, IsMount: GUESS(low)
extern float jumpHeight;
extern float swimmingJumpMultiplier;

static bool IsMount(Actor::BOOL_FLAGS a_flags)
{
    return ((static_cast<std::uint32_t>(a_flags) >> 1) & 1) != 0;
}

bool JumpAnimEventHandler::Handle(Actor* a_actor)
{
    auto* controller = a_actor->GetCharController();
    if (controller && controller->Unk_0F() && !a_actor->IsOnMount()) {
        const auto height = jumpHeight;
        auto scaledHeight = a_actor->GetScale() * height;
        if (controller->context.GetState() == hkpCharacterStateType::kSwimming && !IsMount(a_actor->boolFlags)) {
            scaledHeight *= swimmingJumpMultiplier;
        }
        controller->SetJumpHeight(scaledHeight);
    }
    return true;
}
