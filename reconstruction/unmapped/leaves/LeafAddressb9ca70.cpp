// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9ca70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9ca70 LeafAddressb9ca70::Address
#include "LeafAddressb9ca70.h"
extern unsigned char leaf_global;
void* LeafAddressb9ca70::Address() { return &leaf_global; }
