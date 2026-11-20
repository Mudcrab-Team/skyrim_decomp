// Source exposure: mixed (pinned image listings and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations follow the CommonLibSSE-NG base-class layout.
// MovementControllerAI, MovementControllerNPC, IMovementControllerRegisterInterface: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IMovementMessageInterface, IMovementMotionDrivenControl, IMovementSelectIdle, IMovementDirectControl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IMovementPlannerDirectControl, IAnimationSetCallbackFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function795ea0, Function7968b0, Function7968e0, Function796910, Function797d00: GUESS(low)
// Function798150, Function7983c0, Function7983e0, Function798400, Function7984d0: GUESS(low)
// Function7986b0, Function7986e0, Function798710, Function798740, Function7987f0: GUESS(low)
// Function798820, Function798850, Function798bf0: GUESS(low)
// MovementCallbackData, MotionGate, MovementKey, FunctionSlot01, FunctionSlot02: STANDIN GUESS(low)
// FunctionSlot03, Function798b40, Function798c30, Function1214580, state: STANDIN GUESS(low)
// transitionState, padding, directControlChanged, plannerControlChanged, unk1CA: STANDIN GUESS(low)
// unk1CB: STANDIN GUESS(low)
#pragma once

#include <cstdint>

struct MovementKey;
struct MovementCallbackData;

class MotionGate
{
public:
    virtual ~MotionGate();
    virtual void FunctionSlot01(std::uint32_t enabled);
};

class IMovementControllerRegisterInterface
{
public:
    virtual ~IMovementControllerRegisterInterface();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual MotionGate* FunctionSlot03(const MovementKey& key);
};

class MovementControllerAI : public IMovementControllerRegisterInterface
{
protected:
    // unk078: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t padding08[0x70];
    void* unk078;
    std::uint8_t padding80[0x18];
    std::uint32_t state;
    std::uint8_t padding9C[0x84];
};
static_assert(sizeof(MovementControllerAI) == 0x120, "movement controller base size");

class IMovementMessageInterface
{
public:
    virtual ~IMovementMessageInterface();
};

class IMovementMotionDrivenControl
{
public:
    virtual ~IMovementMotionDrivenControl();
};

class IMovementSelectIdle
{
public:
    virtual ~IMovementSelectIdle();
};

class IMovementDirectControl
{
public:
    virtual ~IMovementDirectControl();
    virtual void Function797d00();
};

class IMovementPlannerDirectControl
{
public:
    virtual ~IMovementPlannerDirectControl();
    virtual void Function798150();
};

class IAnimationSetCallbackFunctor
{
public:
    virtual ~IAnimationSetCallbackFunctor();
    virtual void Function798bf0(void* actor, MovementCallbackData& update);
};

class MovementControllerNPC :
    public MovementControllerAI,
    public IMovementMessageInterface,
    public IMovementMotionDrivenControl,
    public IMovementSelectIdle,
    public IMovementDirectControl,
    public IMovementPlannerDirectControl,
    public IAnimationSetCallbackFunctor
{
public:
    MovementControllerNPC();
    ~MovementControllerNPC() override;
    bool Function795ea0() const;
    bool Function7968b0() const;
    bool Function7968e0() const;
    bool Function796910() const;
    void Function797d00() override;
    void Function798150() override;
    void Function7983c0(bool value);
    void Function7983e0(bool value);
    void Function798400(bool disabled);
    void Function7984d0();
    void Function7986b0();
    void Function7986e0();
    void Function798710();
    void Function798740();
    void Function7987f0();
    void Function798820();
    void Function798850();
    void Function798bf0(void* actor, MovementCallbackData& update) override;

private:
    bool Function1214580(const void* transition);
    void Function798b40();
    void Function798c30();

    // unk188, unk190, unk198: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t padding150[0x38];
    void* unk188;
    std::uint32_t unk190;
    std::uint8_t padding194[4];
    std::uint32_t unk198;
    std::uint8_t padding19C[0x24];
    std::uint32_t transitionState;
    std::uint8_t padding1C4[2];
    bool directControlChanged;
    bool plannerControlChanged;
    std::uint8_t padding1C8[2];
    bool unk1CA;
    bool unk1CB;
    std::uint8_t padding1CC[4];
};
static_assert(sizeof(MovementControllerNPC) == 0x1D0, "NPC movement controller size");
