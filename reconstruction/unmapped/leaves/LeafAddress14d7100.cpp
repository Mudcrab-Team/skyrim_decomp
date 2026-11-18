// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress14d7100, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x14d7100 LeafAddress14d7100::Address
#include "LeafAddress14d7100.h"
extern unsigned char leaf_global;
void* LeafAddress14d7100::Address() { return &leaf_global; }
