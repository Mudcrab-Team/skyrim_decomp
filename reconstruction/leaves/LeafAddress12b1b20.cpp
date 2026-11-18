// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12b1b20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12b1b20 LeafAddress12b1b20::Address
#include "LeafAddress12b1b20.h"
extern unsigned char leaf_global;
void* LeafAddress12b1b20::Address() { return &leaf_global; }
