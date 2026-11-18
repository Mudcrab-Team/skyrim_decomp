// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress59f7c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x59f7c0 LeafAddress59f7c0::Address
#include "LeafAddress59f7c0.h"
extern unsigned char leaf_global;
void* LeafAddress59f7c0::Address() { return &leaf_global; }
