// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress14d6dd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x14d6dd0 LeafAddress14d6dd0::Address
#include "LeafAddress14d6dd0.h"
extern unsigned char leaf_global;
void* LeafAddress14d6dd0::Address() { return &leaf_global; }
