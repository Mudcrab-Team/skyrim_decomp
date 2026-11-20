// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress108c8c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x108c8c0 LeafAddress108c8c0::Address
#include "LeafAddress108c8c0.h"
extern unsigned char leaf_global;
void* LeafAddress108c8c0::Address() { return &leaf_global; }
