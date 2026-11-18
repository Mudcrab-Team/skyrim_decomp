// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e650, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e650 LeafAddressb3e650::Address
#include "LeafAddressb3e650.h"
extern unsigned char leaf_global;
void* LeafAddressb3e650::Address() { return &leaf_global; }
