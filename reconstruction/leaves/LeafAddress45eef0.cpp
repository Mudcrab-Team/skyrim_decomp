// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45eef0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45eef0 LeafAddress45eef0::Address
#include "LeafAddress45eef0.h"
extern unsigned char leaf_global;
void* LeafAddress45eef0::Address() { return &leaf_global; }
