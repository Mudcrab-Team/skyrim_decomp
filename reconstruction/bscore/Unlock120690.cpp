// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock120690: GUESS(low) STANDIN; original owner is unknown
// 0x120690 Unlock120690::~Unlock120690
#include "Unlock120690.h"

Unlock120690::~Unlock120690() {
    auto* data = reinterpret_cast<Data120690*>(tagged & ~static_cast<std::uintptr_t>(3));
    // Tagged string data may be shared between owners.
    if (_InterlockedExchangeAdd(&data->references, -1) == 1) heap->Free(data);
}
