// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf10130, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf10130 NiBooleanExtraData::GetRTTI
#include "LeafAddressf10130.h"
extern unsigned char leaf_global;
void* LeafAddressf10130::Address() { return &leaf_global; }
