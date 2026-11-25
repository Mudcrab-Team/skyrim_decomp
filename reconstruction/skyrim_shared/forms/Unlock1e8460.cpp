// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock1e8460: GUESS(low) STANDIN; original owner is unknown
// Function1e8460: GUESS(low); provisional entry name
// 0x1e8460 Unlock1e8460::Function1e8460
#include "Unlock1e8460.h"

const char* Unlock1e8460::Function1e8460(void* form)
{
    auto* value = static_cast<FullName1e8460*>(RuntimeCast(form, 0, &formType, &nameType, 0));
    return value ? value->GetName() : emptyName;
}
