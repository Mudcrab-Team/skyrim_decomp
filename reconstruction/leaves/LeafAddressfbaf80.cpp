// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfbaf80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfbaf80 LeafAddressfbaf80::Address
#include "LeafAddressfbaf80.h"
extern unsigned char leaf_global;
void* LeafAddressfbaf80::Address() { return &leaf_global; }
