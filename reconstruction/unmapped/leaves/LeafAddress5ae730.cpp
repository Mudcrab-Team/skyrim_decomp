// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5ae730, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5ae730 LeafAddress5ae730::Address
#include "LeafAddress5ae730.h"
extern unsigned char leaf_global;
void* LeafAddress5ae730::Address() { return &leaf_global; }
