// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: bodies written from the local listings; names and declarations follow CommonLibSSE-NG.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x15651e0 BSImagespaceShader::Unk_0D
// 0x1564df0 BSImagespaceShader::RestoreRenderStates
// 0x1564d90 BSImagespaceShader::UpdateParams
// 0x1565170 BSImagespaceShader::Unk_0C
// 0x1564a00 BSImagespaceShader::ShutDown
// 0x1564960 BSImagespaceShader::Setup
// 0x1540db0 BSImagespaceShader::DispatchCopySubRegion
// 0x15411e0 BSImagespaceShader::ResetSubRegionTarget
// ResetSubRegionTarget: GUESS(low)
#include "BSImagespaceShader.h"

// RVA 0x150b490, 3 bytes: an empty slot body.
void BSImagespaceShader::Unk_0B()
{
}

// RVA 0x150b510, 3 bytes: an empty slot body.
void BSImagespaceShader::Unk_0A()
{
}

// RVA 0x15651e0, 13 bytes: the out-pointer is zeroed in place and returned unchanged.
std::uint64_t* BSImagespaceShader::Unk_0D(std::uint64_t* a_out)
{
    *a_out = 0;
    a_out[1] = 0;
    return a_out;
}

// RVA 0x1564df0, 46 bytes: the reset result stays in AL on the early return.
bool BSImagespaceShader::RestoreRenderStates(ImageSpaceEffectParam* a_param)
{
    bool result = ResetRenderStates();
    if (!m_statesDirty) {
        return result;
    }
    return ApplyRenderStates(m_renderState);
}

// RVA 0x1564d90, 79 bytes: no result is returned, so the index stays in the register the call needs.
void BSImagespaceShader::UpdateParams(ImageSpaceEffectParam* a_param)
{
    for (std::uint32_t i = 0; i < m_slotCount; ++i) {
        ImageSpaceSlot* slot = m_slots[i + 1];
        if (slot) {
            SetSlotIndex(slot, i);
        }
    }
}

// RVA 0x1565170, 100 bytes: the last call is a tail jump with a constant true.
void BSImagespaceShader::Unk_0C(std::uint32_t a_x, std::uint32_t a_y, std::uint32_t a_z)
{
    Unk_0A();
    m_renderState->Apply(0, a_x, a_y, a_z);
    Unk_0B();
    FinalizeCommit(true);
}

// RVA 0x1564a00, 117 bytes: shadow-state globals, then a tail call on each path.
void BSImagespaceShader::ShutDown()
{
    if (g_shadowDirtyB) {
        g_shadowFlags |= 0x100;
        g_shadowDirtyB = false;
    }
    if (g_shadowSlotB != 1) {
        g_shadowFlags |= 0x80;
        g_shadowSlotB = 1;
    }
    if (g_shadowModeA != 3) {
        g_shadowModeA = 3;
        if (g_shadowModeB != 3) {
            g_shadowFlags |= 4;
            ApplyShadowState();
            return;
        }
        g_shadowFlags &= ~0x4u;
    }
    ApplyShadowState();
}

// RVA 0x1540db0, 259 bytes: the first qword of the request is the target object.
std::uint32_t BSImagespaceShader::DispatchCopySubRegion(CopySubRegionRequest* a_request)
{
    if (a_request->mode == 0) {
        g_renderer.SetFlagA(0, a_request->value18);
        g_renderer.SetFlagB(0, a_request->value10);
    } else if (a_request->mode == 1) {
        g_renderer.SetFlagC(0, a_request->value3C);
        g_renderer.SetFlagD(0, a_request->value38);
    } else if (a_request->mode == 2) {
        g_renderer.SetFlagE(0, a_request->value34);
        g_renderer.SetFlagF(0, a_request->value30);
    }
    g_renderer.CopyBytes(&a_request->rect, 0x20);
    CopySubRegionToTarget(a_request->target, &a_request->rect);
    a_request->target->Dispatch((a_request->rect.width + 7) >> 3, (a_request->rect.height + 7) >> 3, 1);
    g_renderer.SetFlagA(0, 0);
    g_renderer.SetFlagB(0, 0);
    return 0;
}

bool BSImagespaceShader::Setup(ImageSpaceManager*, ImageSpaceEffectParam*)
{
    bool ready = IsReady(0, 0, 0);
    if (ready) {
        std::uint32_t pending = g_pendingShadowSlot;
        if (g_shadowSlotB != pending) {
            g_shadowSlotB = pending;
            g_shadowFlags |= 0x80;
        }
        if (g_shadowDirtyB) {
            g_shadowFlags |= 0x100;
            g_shadowDirtyB = false;
        }
        if (g_shadowModeA != 0) {
            bool modeBSet = g_shadowModeB != 0;
            g_shadowModeA = 0;
            if (modeBSet) {
                g_shadowFlags |= 4;
            } else {
                g_shadowFlags &= ~0x4u;
            }
        }
    }
    return ready;
}


void BSImagespaceShader::ResetSubRegionTarget(CopySubRegionRequest* a_request)
{
    a_request->target->Slot09(0);
}
