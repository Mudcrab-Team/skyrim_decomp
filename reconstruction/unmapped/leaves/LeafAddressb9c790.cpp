// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c790, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c790 LeafAddressb9c790::Address
#include "LeafAddressb9c790.h"
extern unsigned char leaf_global;
void* LeafAddressb9c790::Address() { return &leaf_global; }
