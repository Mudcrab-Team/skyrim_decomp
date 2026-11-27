// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function164740: GUESS(low); provisional member name
// 0x164740 ExtraDataList::Function164740
// CI hash: 0x164740 ?Function164740@ExtraDataList@@QEAA_NPEA_N@Z
#include "ExtraDataList_164740.h"

// Guess: Return presence and the value of the optional extra-data flag.
bool ExtraDataList::Function164740(bool* output)
{
    auto* data = static_cast<Payload164740*>(GetByType(0x96));
    if (data && data->value) { *output = true; }
    else { *output = false; }
    return data != nullptr;
}
