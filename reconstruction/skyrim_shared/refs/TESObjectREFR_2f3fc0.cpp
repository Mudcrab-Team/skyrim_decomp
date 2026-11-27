// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESObjectREFR: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function2f3fc0: GUESS(low); provisional member name
// 0x2f3fc0 TESObjectREFR::Function2f3fc0
// CI hash: 0x2f3fc0 ?Function2f3fc0@TESObjectREFR@@QEAAXXZ
#include "TESObjectREFR_2f3fc0.h"

// Guess: Find the cell containing the current position and register this reference there.
void TESObjectREFR::Function2f3fc0()
{
    Point2f3fc0 point={position[0],position[1],position[2]};
    bool changed=false;
    auto* next=manager2f3fc0->Find(&point,&changed,0);
    if(next && next!=cell) {
        unsigned identity;
        if(!(references & 0x3ff)) { identity=default2f3fc0; } else { GetIdentity(&identity,this); }
        next->Add(&identity,0);
    }
}
