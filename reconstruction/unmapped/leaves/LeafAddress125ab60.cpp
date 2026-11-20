// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress125ab60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x125ab60 LeafAddress125ab60::Address
#include "LeafAddress125ab60.h"
extern unsigned char leaf_global;
void* LeafAddress125ab60::Address() { return &leaf_global; }
