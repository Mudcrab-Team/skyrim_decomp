// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentPlayerControlsActionTrigger.cpp:51
// MovementHandlerAgentPlayerControlsActionTrigger, Deactivate, MyHandle, hNull, iBits, PlayerControls, UnregisterActor: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// MovementHandlerAgentPlayerControlsActionTrigger, Deactivate: CRASHLOGGER_PDB(59818@2026.10.24)
// BSPointerHandle, BSUntypedPointerHandle, pInstance, unk08, unk18, unk24: GUESS(low)
#pragma once

#include <cstdint>

struct BSPointerHandle
{
    std::uint32_t iBits;
};

struct BSUntypedPointerHandle
{
    static BSPointerHandle hNull;
};

class PlayerControls
{
public:
    void UnregisterActor(BSPointerHandle& a_handle);

    static PlayerControls* pInstance;
};

class MovementHandlerAgentPlayerControlsActionTrigger
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void Deactivate();  // compared: 0x7a5810

    std::uint8_t unk08_[0x10];
    void* unk18;
    BSPointerHandle MyHandle;  // 20
    std::uint32_t unk24;
};
