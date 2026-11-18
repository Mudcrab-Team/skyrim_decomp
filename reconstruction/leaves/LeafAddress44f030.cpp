// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress44f030, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x44f030 LeafAddress44f030::Address
#include "LeafAddress44f030.h"
extern unsigned char leaf_global;
void* LeafAddress44f030::Address() { return &leaf_global; }
