// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function170620: GUESS(low); provisional member name
// 0x170620 ExtraDataList::Function170620
// CI hash: 0x170620 ?Function170620@ExtraDataList@@QEAAPEAPEAXPEAX@Z
#include "ExtraDataList_170620.h"

// Guess: Retrieve or create the extra-data record and expose its value.
void** ExtraDataList::Function170620(void* owner)
{
    auto* data = static_cast<Payload170620*>(GetByType(0xe));
    if (!data) { data = Create(owner); }
    return &data->value;
}
