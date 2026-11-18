// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb52f70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb52f70 LeafAddressb52f70::Address
#include "LeafAddressb52f70.h"
extern unsigned char leaf_global;
void* LeafAddressb52f70::Address() { return &leaf_global; }
