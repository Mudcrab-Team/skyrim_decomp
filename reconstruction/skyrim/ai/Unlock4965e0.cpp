// Source exposure: binary-analysis
// Unlock4965e0: GUESS(low) STANDIN; original owner is unknown
// Function4965e0: GUESS(low); provisional entry name
// 0x4965e0 Unlock4965e0::Function4965e0
#include "Unlock4965e0.h"

void Unlock4965e0::Function4965e0()
{
    found = true; visited = true;
    if (notify) target->flag = true;
}
