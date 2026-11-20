// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfadbd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfadbd0 LeafAddressfadbd0::Address
#include "LeafAddressfadbd0.h"
extern unsigned char leaf_global;
void* LeafAddressfadbd0::Address() { return &leaf_global; }
