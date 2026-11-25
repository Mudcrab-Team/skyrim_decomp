// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function164fa0: GUESS(low); provisional member name
// 0x164fa0 ExtraDataList::Function164fa0
// CI hash: 0x164fa0 ?Function164fa0@ExtraDataList@@QEAAPEAXXZ
#include "ExtraDataList_164fa0.h"

// Guess: Retrieve the pointer carried by the selected extra-data kind.
void* ExtraDataList::Function164fa0()
{
    auto* data = static_cast<Payload164fa0*>(GetByType(168));
    if (data) { return data->value; }
    return nullptr;
}
