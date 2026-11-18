// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress491380, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x491380 LeafAddress491380::Address
#include "LeafAddress491380.h"
extern unsigned char leaf_global;
void* LeafAddress491380::Address() { return &leaf_global; }
