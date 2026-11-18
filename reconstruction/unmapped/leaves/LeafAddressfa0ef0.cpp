// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa0ef0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa0ef0 LeafAddressfa0ef0::Address
#include "LeafAddressfa0ef0.h"
extern unsigned char leaf_global;
void* LeafAddressfa0ef0::Address() { return &leaf_global; }
