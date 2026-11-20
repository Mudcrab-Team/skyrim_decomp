// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10bdab0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10bdab0 LeafAddress10bdab0::Address
#include "LeafAddress10bdab0.h"
extern unsigned char leaf_global;
void* LeafAddress10bdab0::Address() { return &leaf_global; }
