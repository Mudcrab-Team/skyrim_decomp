// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb8db30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb8db30 LeafAddressb8db30::Address
#include "LeafAddressb8db30.h"
extern unsigned char leaf_global;
void* LeafAddressb8db30::Address() { return &leaf_global; }
