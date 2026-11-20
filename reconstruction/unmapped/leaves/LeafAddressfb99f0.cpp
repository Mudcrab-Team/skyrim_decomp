// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb99f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb99f0 LeafAddressfb99f0::Address
#include "LeafAddressfb99f0.h"
extern unsigned char leaf_global;
void* LeafAddressfb99f0::Address() { return &leaf_global; }
