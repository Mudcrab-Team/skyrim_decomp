// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa6b70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa6b70 LeafAddressfa6b70::Address
#include "LeafAddressfa6b70.h"
extern unsigned char leaf_global;
void* LeafAddressfa6b70::Address() { return &leaf_global; }
