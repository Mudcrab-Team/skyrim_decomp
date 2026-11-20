// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf86d70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf86d70 LeafAddressf86d70::Address
#include "LeafAddressf86d70.h"
extern unsigned char leaf_global;
void* LeafAddressf86d70::Address() { return &leaf_global; }
