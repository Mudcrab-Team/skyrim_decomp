// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52e80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52e80 LeafAddressb52e80::Address
#include "LeafAddressb52e80.h"
extern unsigned char leaf_global;
void* LeafAddressb52e80::Address() { return &leaf_global; }
