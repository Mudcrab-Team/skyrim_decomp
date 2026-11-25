// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function165790: GUESS(low); provisional member name
// 0x165790 ExtraDataList::Function165790
// CI hash: 0x165790 ?Function165790@ExtraDataList@@QEAAEXZ
#include "ExtraDataList_165790.h"

// Guess: Read the low flag of a selected extra-data record.
std::uint8_t ExtraDataList::Function165790()
{
    auto* data = static_cast<Payload165790*>(GetByType(0x36));
    return data ? data->flags & 1 : 0;
}
