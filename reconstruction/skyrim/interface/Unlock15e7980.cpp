// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock15e7980: GUESS(low) STANDIN; original owner is unknown
// Function15e7980: GUESS(low); provisional entry name
// 0x15e7980 Unlock15e7980::~Unlock15e7980
#include "Unlock15e7980.h"

Unlock15e7980::~Unlock15e7980()
{
    for (std::size_t index = 0; index < children.size(); ++index) delete children[index];
    children.clear();
}
