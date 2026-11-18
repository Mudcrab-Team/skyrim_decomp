// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfaf7d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfaf7d0 LeafAddressfaf7d0::Address
#include "LeafAddressfaf7d0.h"
extern unsigned char leaf_global;
void* LeafAddressfaf7d0::Address() { return &leaf_global; }
