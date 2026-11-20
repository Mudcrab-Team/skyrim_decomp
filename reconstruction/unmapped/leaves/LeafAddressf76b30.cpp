// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf76b30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf76b30 LeafAddressf76b30::Address
#include "LeafAddressf76b30.h"
extern unsigned char leaf_global;
void* LeafAddressf76b30::Address() { return &leaf_global; }
