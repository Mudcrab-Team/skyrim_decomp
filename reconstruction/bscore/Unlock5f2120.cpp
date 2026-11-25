// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock5f2120: GUESS(low) STANDIN; original owner is unknown
// Function5f2120: GUESS(low); provisional entry name
// 0x5f2120 Unlock5f2120::Function5f2120
#include "Unlock5f2120.h"

void Unlock5f2120::Function5f2120()
{
    if (section) LeaveCriticalSection(section);
}
