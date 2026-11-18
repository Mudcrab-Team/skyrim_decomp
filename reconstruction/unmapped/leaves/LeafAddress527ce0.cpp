// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress527ce0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x527ce0 LeafAddress527ce0::Address
#include "LeafAddress527ce0.h"
extern unsigned char leaf_global;
void* LeafAddress527ce0::Address() { return &leaf_global; }
