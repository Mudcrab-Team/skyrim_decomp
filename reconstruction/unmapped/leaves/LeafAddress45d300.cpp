// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45d300, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45d300 LeafAddress45d300::Address
#include "LeafAddress45d300.h"
extern unsigned char leaf_global;
void* LeafAddress45d300::Address() { return &leaf_global; }
