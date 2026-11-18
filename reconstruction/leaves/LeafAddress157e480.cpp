// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress157e480, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x157e480 LeafAddress157e480::Address
#include "LeafAddress157e480.h"
extern unsigned char leaf_global;
void* LeafAddress157e480::Address() { return &leaf_global; }
