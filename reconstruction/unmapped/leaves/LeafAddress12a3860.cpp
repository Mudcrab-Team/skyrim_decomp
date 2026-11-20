// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12a3860, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12a3860 LeafAddress12a3860::Address
#include "LeafAddress12a3860.h"
extern unsigned char leaf_global;
void* LeafAddress12a3860::Address() { return &leaf_global; }
