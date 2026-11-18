// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress133c530, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x133c530 LeafAddress133c530::Address
#include "LeafAddress133c530.h"
extern unsigned char leaf_global;
void* LeafAddress133c530::Address() { return &leaf_global; }
