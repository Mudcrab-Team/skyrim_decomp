// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb8db20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb8db20 LeafAddressb8db20::Address
#include "LeafAddressb8db20.h"
extern unsigned char leaf_global;
void* LeafAddressb8db20::Address() { return &leaf_global; }
