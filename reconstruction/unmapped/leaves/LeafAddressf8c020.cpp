// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf8c020, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf8c020 LeafAddressf8c020::Address
#include "LeafAddressf8c020.h"
extern unsigned char leaf_global;
void* LeafAddressf8c020::Address() { return &leaf_global; }
