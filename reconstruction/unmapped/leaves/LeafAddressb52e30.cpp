// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52e30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52e30 LeafAddressb52e30::Address
#include "LeafAddressb52e30.h"
extern unsigned char leaf_global;
void* LeafAddressb52e30::Address() { return &leaf_global; }
