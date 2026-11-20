// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10b7650, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10b7650 LeafAddress10b7650::Address
#include "LeafAddress10b7650.h"
extern unsigned char leaf_global;
void* LeafAddress10b7650::Address() { return &leaf_global; }
