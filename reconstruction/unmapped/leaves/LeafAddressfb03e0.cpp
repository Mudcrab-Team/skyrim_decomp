// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb03e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb03e0 LeafAddressfb03e0::Address
#include "LeafAddressfb03e0.h"
extern unsigned char leaf_global;
void* LeafAddressfb03e0::Address() { return &leaf_global; }
