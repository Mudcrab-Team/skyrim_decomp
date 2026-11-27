// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function161b00: GUESS(low); provisional member name
// 0x161b00 ExtraDataList::Function161b00
// CI hash: 0x161b00 ?Function161b00@ExtraDataList@@QEAAXI@Z
#include "ExtraDataList_161b00.h"

// Guess: Update a scalar in the selected extra-data payload.
void ExtraDataList::Function161b00(unsigned value)
{
    auto* data = static_cast<Payload161b00*>(GetByType(25));
    if (data) { data->value = value; }
}
