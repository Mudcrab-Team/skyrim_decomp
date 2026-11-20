// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf0cbd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf0cbd0 NiGeometry::GetRTTI
#include "LeafAddressf0cbd0.h"
extern unsigned char leaf_global;
void* LeafAddressf0cbd0::Address() { return &leaf_global; }
