// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45d700, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45d700 LeafAddress45d700::Address
#include "LeafAddress45d700.h"
extern unsigned char leaf_global;
void* LeafAddress45d700::Address() { return &leaf_global; }
