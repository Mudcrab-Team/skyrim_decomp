// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10bc840, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10bc840 LeafAddress10bc840::Address
#include "LeafAddress10bc840.h"
extern unsigned char leaf_global;
void* LeafAddress10bc840::Address() { return &leaf_global; }
