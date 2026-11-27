// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function161ad0: GUESS(low); provisional member name
// 0x161ad0 ExtraDataList::Function161ad0
// CI hash: 0x161ad0 ?Function161ad0@ExtraDataList@@QEAAXPEBI@Z
#include "ExtraDataList_161ad0.h"

// Guess: Copy the supplied scalar to the selected extra-data record.
void ExtraDataList::Function161ad0(const std::uint32_t* value)
{
    auto* data = static_cast<Payload161ad0*>(GetByType(0x19));
    if (data) { data->value = *value; }
}
