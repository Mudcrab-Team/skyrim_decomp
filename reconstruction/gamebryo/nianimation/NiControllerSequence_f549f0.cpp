// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niscreentexture.cpp:538
// SPDX-License-Identifier: CC0-1.0
// NiControllerSequence: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiControllerSequence::LinkObject: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xf549f0 NiControllerSequence::LinkObject
#include "NiControllerSequence_f549f0.h"

// Link the base object, text keys, owner controller, and version-gated animation notes.
void NiControllerSequence::LinkObject(NiStream& a_stream)
{
    NiObject::LinkObject(a_stream);
    textKeys = a_stream.ReadLinkID();
    owner = a_stream.ReadLinkID();

    if (a_stream.version > 0x15u && a_stream.version < 0x1Du) {
        a_stream.ReadLinkID();
        animNotes = nullptr;
        numNotes = 0;
    }

    if (a_stream.version > 0x1Cu) {
        for (std::uint16_t i = 0; i < numNotes; ++i) {
            animNotes[i] = a_stream.ReadLinkID();
        }
    }
}
