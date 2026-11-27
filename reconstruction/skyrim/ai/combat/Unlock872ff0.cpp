// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock872ff0: GUESS(low) STANDIN; original owner is unknown
// Function872ff0: GUESS(low); provisional entry name
// 0x872ff0 Unlock872ff0::Function872ff0
#include "Unlock872ff0.h"

void Unlock872ff0::Function872ff0(std::uint32_t index)
{
    if (currentNode) { currentNode = currentNode->children[index]; state = 2; }
}
