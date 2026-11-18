// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf86550, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf86550 LeafAddressf86550::Address
#include "LeafAddressf86550.h"
extern unsigned char leaf_global;
void* LeafAddressf86550::Address() { return &leaf_global; }
