// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress3fa230, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x3fa230 LeafAddress3fa230::Address
#include "LeafAddress3fa230.h"
extern unsigned char leaf_global;
void* LeafAddress3fa230::Address() { return &leaf_global; }
