// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf9c110, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf9c110 LeafAddressf9c110::Address
#include "LeafAddressf9c110.h"
extern unsigned char leaf_global;
void* LeafAddressf9c110::Address() { return &leaf_global; }
