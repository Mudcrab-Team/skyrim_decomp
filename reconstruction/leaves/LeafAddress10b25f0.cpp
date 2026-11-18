// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10b25f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10b25f0 LeafAddress10b25f0::Address
#include "LeafAddress10b25f0.h"
extern unsigned char leaf_global;
void* LeafAddress10b25f0::Address() { return &leaf_global; }
