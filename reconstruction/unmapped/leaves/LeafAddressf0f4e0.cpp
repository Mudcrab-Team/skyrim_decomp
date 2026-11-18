// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf0f4e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf0f4e0 NiAlphaAccumulator::GetRTTI
#include "LeafAddressf0f4e0.h"
extern unsigned char leaf_global;
void* LeafAddressf0f4e0::Address() { return &leaf_global; }
