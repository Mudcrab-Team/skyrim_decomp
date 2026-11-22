// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// Code origin:
// SPDX-License-Identifier: CC0-1.0
// 0xfd8bd0 BSWindModifier::LoadBinary
#include "BSWindModifier_fd8bd0.h"

// LoadBinary: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
void BSWindModifier::LoadBinary(NiStream& a_stream)
{
    NiPSysModifier::LoadBinary(a_stream);
    a_stream.iStr->read(&fStrength, 1);
}
