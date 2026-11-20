// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfe0160, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfe0160 LeafAddressfe0160::Address
#include "LeafAddressfe0160.h"
extern unsigned char leaf_global;
void* LeafAddressfe0160::Address() { return &leaf_global; }
