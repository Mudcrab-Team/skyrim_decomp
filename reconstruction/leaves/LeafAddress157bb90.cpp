// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress157bb90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x157bb90 LeafAddress157bb90::Address
#include "LeafAddress157bb90.h"
extern unsigned char leaf_global;
void* LeafAddress157bb90::Address() { return &leaf_global; }
