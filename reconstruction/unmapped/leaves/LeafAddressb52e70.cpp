// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52e70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52e70 LeafAddressb52e70::Address
#include "LeafAddressb52e70.h"
extern unsigned char leaf_global;
void* LeafAddressb52e70::Address() { return &leaf_global; }
