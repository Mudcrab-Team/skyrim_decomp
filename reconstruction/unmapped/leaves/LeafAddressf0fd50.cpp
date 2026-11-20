// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf0fd50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf0fd50 LeafAddressf0fd50::Address
#include "LeafAddressf0fd50.h"
extern unsigned char leaf_global;
void* LeafAddressf0fd50::Address() { return &leaf_global; }
