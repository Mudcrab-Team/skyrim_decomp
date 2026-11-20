// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressff0b70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xff0b70 LeafAddressff0b70::Address
#include "LeafAddressff0b70.h"
extern unsigned char leaf_global;
void* LeafAddressff0b70::Address() { return &leaf_global; }
