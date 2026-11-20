// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf6d740, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf6d740 LeafAddressf6d740::Address
#include "LeafAddressf6d740.h"
extern unsigned char leaf_global;
void* LeafAddressf6d740::Address() { return &leaf_global; }
