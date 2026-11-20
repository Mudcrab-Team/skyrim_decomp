// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressff6ba0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xff6ba0 BSSubIndexTriShape::GetRTTI
#include "LeafAddressff6ba0.h"
extern unsigned char leaf_global;
void* LeafAddressff6ba0::Address() { return &leaf_global; }
