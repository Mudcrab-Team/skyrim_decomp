// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf890f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf890f0 LeafAddressf890f0::Address
#include "LeafAddressf890f0.h"
extern unsigned char leaf_global;
void* LeafAddressf890f0::Address() { return &leaf_global; }
