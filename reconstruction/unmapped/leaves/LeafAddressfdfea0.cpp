// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfdfea0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfdfea0 LeafAddressfdfea0::Address
#include "LeafAddressfdfea0.h"
extern unsigned char leaf_global;
void* LeafAddressfdfea0::Address() { return &leaf_global; }
