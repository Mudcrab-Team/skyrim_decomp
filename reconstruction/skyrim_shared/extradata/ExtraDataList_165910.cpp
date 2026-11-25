// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function165910: GUESS(low); provisional member name
// 0x165910 ExtraDataList::Function165910
// CI hash: 0x165910 ?Function165910@ExtraDataList@@QEAAPEAUPayloadValue165910@@XZ
#include "ExtraDataList_165910.h"

// Guess: Retrieve the value subobject of the selected extra-data record.
PayloadValue165910* ExtraDataList::Function165910()
{
    auto* data = static_cast<Payload165910*>(GetByType(0x37));
    return data ? &data->value : nullptr;
}
