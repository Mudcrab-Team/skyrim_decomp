// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress586360, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x586360 LeafAddress586360::Address
#include "LeafAddress586360.h"
extern unsigned char leaf_global;
void* LeafAddress586360::Address() { return &leaf_global; }
