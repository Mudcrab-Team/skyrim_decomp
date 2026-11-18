// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10b1bd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10b1bd0 LeafAddress10b1bd0::Address
#include "LeafAddress10b1bd0.h"
extern unsigned char leaf_global;
void* LeafAddress10b1bd0::Address() { return &leaf_global; }
