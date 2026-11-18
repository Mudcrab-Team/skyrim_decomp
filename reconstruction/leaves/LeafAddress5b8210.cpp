// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5b8210, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5b8210 LeafAddress5b8210::Address
#include "LeafAddress5b8210.h"
extern unsigned char leaf_global;
void* LeafAddress5b8210::Address() { return &leaf_global; }
