// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfab6e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfab6e0 LeafAddressfab6e0::Address
#include "LeafAddressfab6e0.h"
extern unsigned char leaf_global;
void* LeafAddressfab6e0::Address() { return &leaf_global; }
