// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf1b900, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf1b900 LeafAddressf1b900::Address
#include "LeafAddressf1b900.h"
extern unsigned char leaf_global;
void* LeafAddressf1b900::Address() { return &leaf_global; }
