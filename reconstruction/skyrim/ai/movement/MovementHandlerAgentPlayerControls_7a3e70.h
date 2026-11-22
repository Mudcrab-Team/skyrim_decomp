// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// MovementHandlerAgentPlayerControls::Func10_1406FB930: CRASHLOGGER_PDB(59818@2026.10.24)
// MovementHandlerAgentPlayerControls::registerInterface, MovementHandlerAgentPlayerControls::state, IRegisterInterface, IRegisterInterface::Unregister, PlayerControlsState, g_registerKey: GUESS(low)
#pragma once

struct RegisterKey;
extern const RegisterKey g_registerKey;

struct IRegisterInterface
{
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void Unregister(const RegisterKey* key);
};

struct PlayerControlsState
{
    unsigned char unk000[0x218];
};

class MovementHandlerAgentPlayerControls
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
    virtual void Func10_1406FB930();

    unsigned char pad08[0x20];
    IRegisterInterface* registerInterface;
    unsigned char pad30[0x10];
    PlayerControlsState* state;
};
