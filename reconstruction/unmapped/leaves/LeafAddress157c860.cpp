// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress157c860, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x157c860 LeafAddress157c860::Address
#include "LeafAddress157c860.h"
extern unsigned char leaf_global;
void* LeafAddress157c860::Address() { return &leaf_global; }
