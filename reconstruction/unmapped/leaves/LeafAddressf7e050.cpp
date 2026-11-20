// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7e050, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7e050 LeafAddressf7e050::Address
#include "LeafAddressf7e050.h"
extern unsigned char leaf_global;
void* LeafAddressf7e050::Address() { return &leaf_global; }
