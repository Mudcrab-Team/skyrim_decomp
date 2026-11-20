// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf11160, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf11160 NiFloatExtraData::GetRTTI
#include "LeafAddressf11160.h"
extern unsigned char leaf_global;
void* LeafAddressf11160::Address() { return &leaf_global; }
