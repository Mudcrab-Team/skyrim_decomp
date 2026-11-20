// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3f830, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3f830 LeafAddressb3f830::Address
#include "LeafAddressb3f830.h"
extern unsigned char leaf_global;
void* LeafAddressb3f830::Address() { return &leaf_global; }
