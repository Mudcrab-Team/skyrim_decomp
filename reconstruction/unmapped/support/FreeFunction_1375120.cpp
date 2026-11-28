// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x1375120 Function1375120
// Adapted bodies: none
#include "FreeFunction_1375120.h"

// Closes conn->handle once via atomic closing flag, recording the first error and clearing active.
void Function1375120(Connection_1375120* conn)
{
    // Atomically claim the closing flag so only one thread closes conn->handle.
    if (conn->handle != nullptr && _InterlockedExchange8(&conn->closing, 1) == 0) {
        if (CloseHandle(conn->handle) == 0) {
            std::uint32_t err = GetLastError();
            if (conn->lastError == 0 && err != 0) {
                conn->lastError = err;
                Function1375120(conn);
            }
            // Atomically clear the active flag after close failure handling finishes.
            _InterlockedExchange8(&conn->active, 0);
        }
    }
}
