// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress441480, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x441480 LeafAddress441480::Address
#include "LeafAddress441480.h"
extern unsigned char leaf_global;
void* LeafAddress441480::Address() { return &leaf_global; }
