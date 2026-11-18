// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10d24a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10d24a0 LeafAddress10d24a0::Address
#include "LeafAddress10d24a0.h"
extern unsigned char leaf_global;
void* LeafAddress10d24a0::Address() { return &leaf_global; }
