// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfb81c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfb81c0 LeafAddressfb81c0::Address
#include "LeafAddressfb81c0.h"
extern unsigned char leaf_global;
void* LeafAddressfb81c0::Address() { return &leaf_global; }
