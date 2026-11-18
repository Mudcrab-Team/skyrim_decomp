// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress6076c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x6076c0 LeafAddress6076c0::Address
#include "LeafAddress6076c0.h"
extern unsigned char leaf_global;
void* LeafAddress6076c0::Address() { return &leaf_global; }
