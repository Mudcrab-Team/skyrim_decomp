// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1296810, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1296810 LeafAddress1296810::Address
#include "LeafAddress1296810.h"
extern unsigned char leaf_global;
void* LeafAddress1296810::Address() { return &leaf_global; }
