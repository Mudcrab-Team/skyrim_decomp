// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress157cd00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x157cd00 LeafAddress157cd00::Address
#include "LeafAddress157cd00.h"
extern unsigned char leaf_global;
void* LeafAddress157cd00::Address() { return &leaf_global; }
