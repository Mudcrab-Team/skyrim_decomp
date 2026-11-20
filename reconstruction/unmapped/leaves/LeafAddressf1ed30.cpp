// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf1ed30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf1ed30 LeafAddressf1ed30::Address
#include "LeafAddressf1ed30.h"
extern unsigned char leaf_global;
void* LeafAddressf1ed30::Address() { return &leaf_global; }
