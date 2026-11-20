// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbEventBase; size 0x10
#pragma once

#include "SystemEventIDs.h"
#include "hkRefPtr_RE__hkbEventPayload_b7323dc0.h"
struct hkbEventBase {
    SystemEventIDs id;
    unsigned int pad04;
    hkRefPtr_RE__hkbEventPayload_b7323dc0 payload;
};
static_assert(sizeof(hkbEventBase) == 16, "hkbEventBase layout differs from the PDB");
