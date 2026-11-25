// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESLeveledList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1e9a80: GUESS(low); provisional member name
// 0x1e9a80 TESLeveledList::Function1e9a80
// CI hash: 0x1e9a80 ?Function1e9a80@TESLeveledList@@QEAAXPEBUEntries1e9a80@@@Z
#include "TESLeveledList_1e9a80.h"

// Guess: Append each source record to the leveled list.
void TESLeveledList::Function1e9a80(const Entries1e9a80* source)
{
    for (unsigned i = 0; i < source->count; ++i) {
        auto& value = source->data[i];
        Add(value.form, value.count, &value.extra);
    }
}
