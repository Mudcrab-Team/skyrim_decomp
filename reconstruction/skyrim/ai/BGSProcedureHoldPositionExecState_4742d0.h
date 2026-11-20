// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureHoldPositionExecState: EXE_RTTI
// ApplyActorPosition, ApplyPosition, HoldPositionRequest, HoldPositionSettings, HoldPositionState, PositionController, controller, position, settings, state, unknown00: GUESS(low)
#pragma once

#include <cstdint>

class PositionController;

struct HoldPositionSettings
{
    std::uint8_t unknown00[0x160];
    PositionController* controller;
};

struct HoldPositionState
{
    std::uint8_t unknown00[0x8];
    const void* position;
};

struct HoldPositionRequest
{
    const HoldPositionSettings* settings;
    const HoldPositionState* state;
};

class BGSProcedureHoldPositionExecState
{
public:
    void ApplyPosition(const HoldPositionRequest& request);
};
