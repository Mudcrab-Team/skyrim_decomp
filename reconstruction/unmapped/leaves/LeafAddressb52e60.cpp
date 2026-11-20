// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52e60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52e60 LeafAddressb52e60::Address
#include "LeafAddressb52e60.h"
extern unsigned char leaf_global;
void* LeafAddressb52e60::Address() { return &leaf_global; }
