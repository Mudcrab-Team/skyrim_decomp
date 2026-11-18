// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressefe630, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xefe630 NiPointLight::GetRTTI
#include "LeafAddressefe630.h"
extern unsigned char leaf_global;
void* LeafAddressefe630::Address() { return &leaf_global; }
