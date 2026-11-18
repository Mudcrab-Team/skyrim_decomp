// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10d2540, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10d2540 LeafAddress10d2540::Address
#include "LeafAddress10d2540.h"
extern unsigned char leaf_global;
void* LeafAddress10d2540::Address() { return &leaf_global; }
