// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function172f20: GUESS(low); provisional member name
// 0x172f20 ExtraDataList::Function172f20
// CI hash: 0x172f20 ?Function172f20@ExtraDataList@@QEAAHPEAX@Z
#include "ExtraDataList_172f20.h"

// Guess: Find a value within the selected extra-data record.
int ExtraDataList::Function172f20(void* value)
{
    auto* data = static_cast<Payload172f20*>(GetByType(0x88));
    return data ? data->Find(value) : -1;
}
