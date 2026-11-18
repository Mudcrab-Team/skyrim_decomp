// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf05930, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf05930 NiParticles::GetRTTI
#include "LeafAddressf05930.h"
extern unsigned char leaf_global;
void* LeafAddressf05930::Address() { return &leaf_global; }
