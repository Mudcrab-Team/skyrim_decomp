// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa7c70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa7c70 LeafAddressfa7c70::Address
#include "LeafAddressfa7c70.h"
extern unsigned char leaf_global;
void* LeafAddressfa7c70::Address() { return &leaf_global; }
