// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5ae740, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5ae740 LeafAddress5ae740::Address
#include "LeafAddress5ae740.h"
extern unsigned char leaf_global;
void* LeafAddress5ae740::Address() { return &leaf_global; }
