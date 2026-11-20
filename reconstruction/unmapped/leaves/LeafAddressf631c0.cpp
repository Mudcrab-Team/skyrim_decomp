// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf631c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf631c0 LeafAddressf631c0::Address
#include "LeafAddressf631c0.h"
extern unsigned char leaf_global;
void* LeafAddressf631c0::Address() { return &leaf_global; }
