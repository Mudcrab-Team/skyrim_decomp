// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf75630, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf75630 LeafAddressf75630::Address
#include "LeafAddressf75630.h"
extern unsigned char leaf_global;
void* LeafAddressf75630::Address() { return &leaf_global; }
