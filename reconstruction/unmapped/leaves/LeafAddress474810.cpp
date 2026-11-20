// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress474810, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x474810 LeafAddress474810::Address
#include "LeafAddress474810.h"
extern unsigned char leaf_global;
void* LeafAddress474810::Address() { return &leaf_global; }
