// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa2b60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa2b60 LeafAddressfa2b60::Address
#include "LeafAddressfa2b60.h"
extern unsigned char leaf_global;
void* LeafAddressfa2b60::Address() { return &leaf_global; }
