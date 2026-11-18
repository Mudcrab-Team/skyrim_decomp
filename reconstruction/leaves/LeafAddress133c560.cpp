// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress133c560, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x133c560 LeafAddress133c560::Address
#include "LeafAddress133c560.h"
extern unsigned char leaf_global;
void* LeafAddress133c560::Address() { return &leaf_global; }
