// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf88780, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf88780 LeafAddressf88780::Address
#include "LeafAddressf88780.h"
extern unsigned char leaf_global;
void* LeafAddressf88780::Address() { return &leaf_global; }
