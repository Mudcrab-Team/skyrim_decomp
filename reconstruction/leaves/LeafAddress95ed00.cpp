// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress95ed00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x95ed00 LeafAddress95ed00::Address
#include "LeafAddress95ed00.h"
extern unsigned char leaf_global;
void* LeafAddress95ed00::Address() { return &leaf_global; }
