// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress122810, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x122810 LeafAddress122810::Address
#include "LeafAddress122810.h"
extern unsigned char leaf_global;
void* LeafAddress122810::Address() { return &leaf_global; }
