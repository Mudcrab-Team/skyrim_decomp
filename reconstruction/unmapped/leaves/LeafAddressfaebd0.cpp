// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfaebd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfaebd0 LeafAddressfaebd0::Address
#include "LeafAddressfaebd0.h"
extern unsigned char leaf_global;
void* LeafAddressfaebd0::Address() { return &leaf_global; }
