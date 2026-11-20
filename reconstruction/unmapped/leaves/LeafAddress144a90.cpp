// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress144a90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x144a90 LeafAddress144a90::Address
#include "LeafAddress144a90.h"
extern unsigned char leaf_global;
void* LeafAddress144a90::Address() { return &leaf_global; }
