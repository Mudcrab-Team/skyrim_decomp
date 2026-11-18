// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52f20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52f20 LeafAddressb52f20::Address
#include "LeafAddressb52f20.h"
extern unsigned char leaf_global;
void* LeafAddressb52f20::Address() { return &leaf_global; }
