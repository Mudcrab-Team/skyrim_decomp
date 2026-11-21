// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureFlightGrab: EXE_RTTI
// DispatchModes2And3, DispatchModes0And1, DispatchMode, FlightGrabModeRequest, FlightGrabSettings, mode, settings, unknown00: GUESS(low)
#pragma once

#include "BGSProcedureBase_45bfe0.h"

struct FlightGrabSettings
{
    std::uint8_t unknown00[0x34];
    std::int32_t mode;
};

struct FlightGrabModeRequest
{
    const FlightGrabSettings* settings;
};

class BGSProcedureFlightGrab : public BGSProcedureBase
{
public:
    void DispatchMode(const FlightGrabModeRequest& request);
};
