// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress605620, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x605620 LeafAddress605620::Address
#include "LeafAddress605620.h"
extern unsigned char leaf_global;
void* LeafAddress605620::Address() { return &leaf_global; }
