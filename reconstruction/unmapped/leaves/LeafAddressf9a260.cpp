// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf9a260, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf9a260 NiParticleSystem::GetRTTI
#include "LeafAddressf9a260.h"
extern unsigned char leaf_global;
void* LeafAddressf9a260::Address() { return &leaf_global; }
