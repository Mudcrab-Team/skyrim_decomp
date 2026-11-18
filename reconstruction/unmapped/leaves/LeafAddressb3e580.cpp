// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e580, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e580 LeafAddressb3e580::Address
#include "LeafAddressb3e580.h"
extern unsigned char leaf_global;
void* LeafAddressb3e580::Address() { return &leaf_global; }
