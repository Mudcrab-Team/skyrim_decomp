// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa24d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa24d0 LeafAddressfa24d0::Address
#include "LeafAddressfa24d0.h"
extern unsigned char leaf_global;
void* LeafAddressfa24d0::Address() { return &leaf_global; }
