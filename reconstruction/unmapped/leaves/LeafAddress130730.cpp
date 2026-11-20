// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress130730, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x130730 LeafAddress130730::Address
#include "LeafAddress130730.h"
extern unsigned char leaf_global;
void* LeafAddress130730::Address() { return &leaf_global; }
