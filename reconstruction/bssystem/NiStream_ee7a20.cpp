// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream::RTTIError: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xee7a20 NiStream::RTTIError
#include "NiStream_ee7a20.h"

#include <cstring>

// Record an RTTI lookup failure and build the error message buffer.
void NiStream::RTTIError(const char* a_rttiName)
{
    lastError = 5;
    strcpy_s(lastErrorMessage, sizeof(lastErrorMessage), a_rttiName);
    strcat_s(lastErrorMessage, sizeof(lastErrorMessage), gRttiErrorSuffix);
}
