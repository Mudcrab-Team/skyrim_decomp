// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4b04e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4b04e0 BSTempEffectParticle::GetRTTI
#include "LeafAddress4b04e0.h"
extern unsigned char leaf_global;
void* LeafAddress4b04e0::Address() { return &leaf_global; }
