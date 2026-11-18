// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb58e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb58e0 LeafAddressfb58e0::Address
#include "LeafAddressfb58e0.h"
extern unsigned char leaf_global;
void* LeafAddressfb58e0::Address() { return &leaf_global; }
