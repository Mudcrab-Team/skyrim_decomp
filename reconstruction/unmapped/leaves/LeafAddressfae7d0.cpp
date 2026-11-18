// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfae7d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfae7d0 LeafAddressfae7d0::Address
#include "LeafAddressfae7d0.h"
extern unsigned char leaf_global;
void* LeafAddressfae7d0::Address() { return &leaf_global; }
