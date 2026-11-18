// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e630, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e630 LeafAddressb3e630::Address
#include "LeafAddressb3e630.h"
extern unsigned char leaf_global;
void* LeafAddressb3e630::Address() { return &leaf_global; }
