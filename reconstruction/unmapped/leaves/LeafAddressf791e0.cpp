// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf791e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf791e0 LeafAddressf791e0::Address
#include "LeafAddressf791e0.h"
extern unsigned char leaf_global;
void* LeafAddressf791e0::Address() { return &leaf_global; }
