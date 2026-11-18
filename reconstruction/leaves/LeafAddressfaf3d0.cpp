// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfaf3d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfaf3d0 LeafAddressfaf3d0::Address
#include "LeafAddressfaf3d0.h"
extern unsigned char leaf_global;
void* LeafAddressfaf3d0::Address() { return &leaf_global; }
