// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress3acba0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x3acba0 LeafAddress3acba0::Address
#include "LeafAddress3acba0.h"
extern unsigned char leaf_global;
void* LeafAddress3acba0::Address() { return &leaf_global; }
