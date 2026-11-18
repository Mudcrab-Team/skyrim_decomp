// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress47d490, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x47d490 LeafAddress47d490::Address
#include "LeafAddress47d490.h"
extern unsigned char leaf_global;
void* LeafAddress47d490::Address() { return &leaf_global; }
