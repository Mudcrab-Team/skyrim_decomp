// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10ad620, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10ad620 LeafAddress10ad620::Address
#include "LeafAddress10ad620.h"
extern unsigned char leaf_global;
void* LeafAddress10ad620::Address() { return &leaf_global; }
