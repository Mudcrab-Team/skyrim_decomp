// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress157c250, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x157c250 LeafAddress157c250::Address
#include "LeafAddress157c250.h"
extern unsigned char leaf_global;
void* LeafAddress157c250::Address() { return &leaf_global; }
