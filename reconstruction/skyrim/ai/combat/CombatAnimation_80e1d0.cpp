// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// CombatAnimation: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function80e1d0: GUESS(low); provisional member name
// 0x80e1d0 CombatAnimation::Function80e1d0
// CI hash: 0x80e1d0 ?Function80e1d0@CombatAnimation@@QEAA_NPEAX0@Z
#include "CombatAnimation_80e1d0.h"

// Guess: Resolve an animation binding once and apply it when available.
bool CombatAnimation::Function80e1d0(void* first,void* second)
{
    unsigned current=state;
    if(!current) { current=object->Find(&description,&binding)?1:2; state=current; }
    if(current!=2) { return binding.Apply(first,second); }
    return false;
}
