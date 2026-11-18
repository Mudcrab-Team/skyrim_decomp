// Source exposure: binary-analysis; no external implementation reused.
// LeafAddresseed240, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xeed240 NiLight::GetRTTI
#include "LeafAddresseed240.h"
extern unsigned char leaf_global;
void* LeafAddresseed240::Address() { return &leaf_global; }
