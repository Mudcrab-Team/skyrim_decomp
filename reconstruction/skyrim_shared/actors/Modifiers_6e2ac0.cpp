// Source exposure: mixed (the listing of the pinned image; names from the sibling declarations used by the adapted body).
// Code origin: body adapted from the sibling function below; callee and loop bound checked against the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/ActorValueStorage.cpp:66
// 0x6e2ac0 Modifiers::LoadGame
#include "Modifiers_6e2ac0.h"

// Fewer saved values than slots: the rest start at zero.
void Modifiers::LoadGame(BGSLoadFormBuffer* a_buffer)
{
    unsigned int count = 0;
    a_buffer->LoadDataEndian(&count, 4u, 4u);
    for (unsigned int i = 0; i < 3; ++i) {
        if (i < count) {
            a_buffer->LoadDataEndian(&fModifiers[i], 4u, 4u);
        } else {
            fModifiers[i] = 0.0f;
        }
    }
}
