// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress108bbb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x108bbb0 LeafAddress108bbb0::Address
#include "LeafAddress108bbb0.h"
extern unsigned char leaf_global;
void* LeafAddress108bbb0::Address() { return &leaf_global; }
