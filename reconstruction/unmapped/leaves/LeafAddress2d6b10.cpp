// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress2d6b10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x2d6b10 LeafAddress2d6b10::Address
#include "LeafAddress2d6b10.h"
extern unsigned char leaf_global;
void* LeafAddress2d6b10::Address() { return &leaf_global; }
