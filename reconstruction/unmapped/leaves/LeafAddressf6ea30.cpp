// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf6ea30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf6ea30 NiKeyBasedInterpolator::GetRTTI
#include "LeafAddressf6ea30.h"
extern unsigned char leaf_global;
void* LeafAddressf6ea30::Address() { return &leaf_global; }
