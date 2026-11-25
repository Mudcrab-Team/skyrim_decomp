// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiAVObject: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function104cdf0: GUESS(low); provisional member name
// 0x104cdf0 NiAVObject::Function104cdf0
// CI hash: 0x104cdf0 ?Function104cdf0@NiAVObject@@QEAA_N_N0@Z
#include "NiAVObject_104cdf0.h"

// Guess: Apply a Havok property command when the object or force flag allows it.
bool NiAVObject::Function104cdf0(bool enabled, bool force)
{
    if (!this) { return false; }
    if (!force) {
        auto* state = GetState();
        if (!state || !(state->flags & 2)) { return false; }
    }
    Command104cdf0 command;
    command.value = nullptr;
    command.enabled = enabled;
    command.kind = 4;
    if (commandKey104cdf0) { Apply(&command, commandKey104cdf0); }
    return true;
}
