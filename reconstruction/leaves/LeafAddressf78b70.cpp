// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf78b70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf78b70 LeafAddressf78b70::Address
#include "LeafAddressf78b70.h"
extern unsigned char leaf_global;
void* LeafAddressf78b70::Address() { return &leaf_global; }
