// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiBinaryStream::Write as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitransform.cpp:25
// SPDX-License-Identifier: CC0-1.0
// NiTimeController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiTimeController::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xef8040 NiTimeController::SaveBinary
#include "NiTimeController_ef8040.h"

// Save the next streamable controller link, timing parameters, and target link.
void NiTimeController::SaveBinary(NiStream& a_stream)
{
    NiObject::SaveBinary(a_stream);

    NiTimeController* nextCtrl = next;
    while (nextCtrl && !nextCtrl->IsStreamable()) {
        nextCtrl = nextCtrl->next;
    }
    a_stream.SaveLinkID(nextCtrl);

    a_stream.oStr->Write(&flags);
    a_stream.oStr->Write(&frequency);
    a_stream.oStr->Write(&phase);
    a_stream.oStr->Write(&loKeyTime);
    a_stream.oStr->Write(&hiKeyTime);
    a_stream.SaveLinkID(target);
}
