// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf8a120, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf8a120 LeafAddressf8a120::Address
#include "LeafAddressf8a120.h"
extern unsigned char leaf_global;
void* LeafAddressf8a120::Address() { return &leaf_global; }
