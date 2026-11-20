// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb3e6a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb3e6a0 LeafAddressb3e6a0::Address
#include "LeafAddressb3e6a0.h"
extern unsigned char leaf_global;
void* LeafAddressb3e6a0::Address() { return &leaf_global; }
