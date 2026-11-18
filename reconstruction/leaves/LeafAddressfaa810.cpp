// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfaa810, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfaa810 LeafAddressfaa810::Address
#include "LeafAddressfaa810.h"
extern unsigned char leaf_global;
void* LeafAddressfaa810::Address() { return &leaf_global; }
