// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfce6d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfce6d0 LeafAddressfce6d0::Address
#include "LeafAddressfce6d0.h"
extern unsigned char leaf_global;
void* LeafAddressfce6d0::Address() { return &leaf_global; }
