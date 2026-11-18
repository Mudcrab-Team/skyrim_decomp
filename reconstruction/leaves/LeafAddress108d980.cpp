// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress108d980, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x108d980 LeafAddress108d980::Address
#include "LeafAddress108d980.h"
extern unsigned char leaf_global;
void* LeafAddress108d980::Address() { return &leaf_global; }
