// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfafbd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfafbd0 LeafAddressfafbd0::Address
#include "LeafAddressfafbd0.h"
extern unsigned char leaf_global;
void* LeafAddressfafbd0::Address() { return &leaf_global; }
