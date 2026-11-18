// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e660, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e660 LeafAddressb3e660::Address
#include "LeafAddressb3e660.h"
extern unsigned char leaf_global;
void* LeafAddressb3e660::Address() { return &leaf_global; }
