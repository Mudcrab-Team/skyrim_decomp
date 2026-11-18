// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10ae1b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10ae1b0 LeafAddress10ae1b0::Address
#include "LeafAddress10ae1b0.h"
extern unsigned char leaf_global;
void* LeafAddress10ae1b0::Address() { return &leaf_global; }
