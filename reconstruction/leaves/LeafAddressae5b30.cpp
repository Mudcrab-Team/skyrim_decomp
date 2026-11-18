// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5b30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5b30 LeafAddressae5b30::Address
#include "LeafAddressae5b30.h"
extern unsigned char leaf_global;
void* LeafAddressae5b30::Address() { return &leaf_global; }
