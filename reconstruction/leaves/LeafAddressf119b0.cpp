// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf119b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf119b0 NiFloatsExtraData::GetRTTI
#include "LeafAddressf119b0.h"
extern unsigned char leaf_global;
void* LeafAddressf119b0::Address() { return &leaf_global; }
