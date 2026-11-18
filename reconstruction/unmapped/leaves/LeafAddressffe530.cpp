// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressffe530, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xffe530 LeafAddressffe530::Address
#include "LeafAddressffe530.h"
extern unsigned char leaf_global;
void* LeafAddressffe530::Address() { return &leaf_global; }
