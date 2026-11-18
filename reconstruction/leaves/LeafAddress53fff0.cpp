// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress53fff0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x53fff0 LeafAddress53fff0::Address
#include "LeafAddress53fff0.h"
extern unsigned char leaf_global;
void* LeafAddress53fff0::Address() { return &leaf_global; }
