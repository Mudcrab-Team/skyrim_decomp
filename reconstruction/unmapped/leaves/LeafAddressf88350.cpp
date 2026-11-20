// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf88350, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf88350 LeafAddressf88350::Address
#include "LeafAddressf88350.h"
extern unsigned char leaf_global;
void* LeafAddressf88350::Address() { return &leaf_global; }
