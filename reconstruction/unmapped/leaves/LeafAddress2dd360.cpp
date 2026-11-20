// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2dd360, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2dd360 LeafAddress2dd360::Address
#include "LeafAddress2dd360.h"
extern unsigned char leaf_global;
void* LeafAddress2dd360::Address() { return &leaf_global; }
