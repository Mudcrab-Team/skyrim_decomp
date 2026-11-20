// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb8600, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb8600 LeafAddressfb8600::Address
#include "LeafAddressfb8600.h"
extern unsigned char leaf_global;
void* LeafAddressfb8600::Address() { return &leaf_global; }
