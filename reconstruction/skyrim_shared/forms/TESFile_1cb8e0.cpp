// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x1cb8e0 TESFile::IsHigherVersionThanSupported
// Adapted bodies: none
#include "TESFile_1cb8e0.h"

#include <intrin.h>

// Checks whether the file header version exceeds the supported version and formats a warning.
bool TESFile::IsHigherVersionThanSupported() const
{
    if (!(version <= 1.71f)) {
        // atomic counter: shared warning-suppression counter modified with interlocked ops
        _InterlockedDecrement(&g_warningSuppressionCount);
        if (g_warningSuppressionCount < 0) {
            g_warningSuppressionCount = 0;
        }

        char message[260];
        FormatWarningMessage(message, sizeof(message), g_higherVersionFormat, fileName, static_cast<double>(version), 1.71);

        // atomic counter: restore shared warning-suppression counter after formatting
        _InterlockedIncrement(&g_warningSuppressionCount);
        if (g_warningSuppressionCount < 0) {
            g_warningSuppressionCount = 0;
        }

        return true;
    }

    return false;
}
