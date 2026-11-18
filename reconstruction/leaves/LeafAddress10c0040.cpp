// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10c0040, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10c0040 LeafAddress10c0040::Address
#include "LeafAddress10c0040.h"
extern unsigned char leaf_global;
void* LeafAddress10c0040::Address() { return &leaf_global; }
