// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf19350, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf19350 LeafAddressf19350::Address
#include "LeafAddressf19350.h"
extern unsigned char leaf_global;
void* LeafAddressf19350::Address() { return &leaf_global; }
