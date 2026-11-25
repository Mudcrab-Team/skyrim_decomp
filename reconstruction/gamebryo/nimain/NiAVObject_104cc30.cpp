// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiAVObject: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function104cc30: GUESS(low); provisional member name
// 0x104cc30 NiAVObject::Function104cc30
// CI hash: 0x104cc30 ?Function104cc30@NiAVObject@@QEAA_N_N0@Z
#include "NiAVObject_104cc30.h"

// Guess: Apply a Havok property command when the object or force flag allows it.
bool NiAVObject::Function104cc30(bool enabled, bool force)
{
    if (!this) { return false; }
    if (!force) {
        auto* state = GetState();
        if (!state || !(state->flags & 2)) { return false; }
    }
    Command104cc30 command;
    command.value = nullptr;
    command.enabled = enabled;
    command.kind = 2;
    if (commandKey104cc30) { Apply(&command, commandKey104cc30); }
    return true;
}
