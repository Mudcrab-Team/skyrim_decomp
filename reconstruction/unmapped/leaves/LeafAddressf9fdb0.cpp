// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf9fdb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf9fdb0 BSStripParticleSystem::GetRTTI
#include "LeafAddressf9fdb0.h"
extern unsigned char leaf_global;
void* LeafAddressf9fdb0::Address() { return &leaf_global; }
