// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c870, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c870 LeafAddressb9c870::Address
#include "LeafAddressb9c870.h"
extern unsigned char leaf_global;
void* LeafAddressb9c870::Address() { return &leaf_global; }
