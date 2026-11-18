// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c820, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c820 LeafAddressb9c820::Address
#include "LeafAddressb9c820.h"
extern unsigned char leaf_global;
void* LeafAddressb9c820::Address() { return &leaf_global; }
