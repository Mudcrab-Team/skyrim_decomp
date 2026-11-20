// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x46d6e0 BGSProcedureFlightGrab::DispatchMode
#include "BGSProcedureFlightGrab_46d6e0.h"

void DispatchModes0And1(BGSProcedureFlightGrab& procedure, const FlightGrabModeRequest& request, std::int32_t mode);
void DispatchModes2And3(BGSProcedureFlightGrab& procedure, const FlightGrabModeRequest& request, std::int32_t mode);

void BGSProcedureFlightGrab::DispatchMode(const FlightGrabModeRequest& request)
{
    const auto mode = request.settings->mode;
    switch (mode) {
    case 0:
    case 1:
        return DispatchModes0And1(*this, request, mode);
    case 2:
    case 3:
        return DispatchModes2And3(*this, request, mode);
    }
}
