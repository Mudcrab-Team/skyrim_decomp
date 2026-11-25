// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function676810: GUESS(low); provisional member name
// 0x676810 Actor::Function676810
// CI hash: 0x676810 ?Function676810@Actor@@QEAAXXZ
#include "Actor_676810.h"

// Guess: Save the actor position, heading, and current cell or world context.
void Actor::Function676810()
{
    saved[0]=position[0]; saved[1]=position[1]; saved[2]=position[2];
    heading=GetHeading(false);
    auto* current=cell;
    World676810* world=nullptr;
    if(current && (current->flags & 1)) { interior=current; }
    else { world=GetWorld(); interior=world; }
    if(current) { context=current->GetContext(); }
    else if(world) { context=world->Find(saved); }

}
