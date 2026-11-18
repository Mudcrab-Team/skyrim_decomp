// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress465480, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x465480 LeafAddress465480::Address
#include "LeafAddress465480.h"
extern unsigned char leaf_global;
void* LeafAddress465480::Address() { return &leaf_global; }
