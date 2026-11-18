// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf04710, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf04710 NiDirectionalLight::GetRTTI
#include "LeafAddressf04710.h"
extern unsigned char leaf_global;
void* LeafAddressf04710::Address() { return &leaf_global; }
