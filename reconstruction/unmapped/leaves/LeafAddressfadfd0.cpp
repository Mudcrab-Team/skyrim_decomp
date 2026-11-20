// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfadfd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfadfd0 LeafAddressfadfd0::Address
#include "LeafAddressfadfd0.h"
extern unsigned char leaf_global;
void* LeafAddressfadfd0::Address() { return &leaf_global; }
