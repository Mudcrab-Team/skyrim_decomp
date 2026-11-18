// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10017b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10017b0 LeafAddress10017b0::Address
#include "LeafAddress10017b0.h"
extern unsigned char leaf_global;
void* LeafAddress10017b0::Address() { return &leaf_global; }
