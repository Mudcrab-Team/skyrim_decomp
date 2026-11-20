// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress158e140, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x158e140 LeafAddress158e140::Address
#include "LeafAddress158e140.h"
extern unsigned char leaf_global;
void* LeafAddress158e140::Address() { return &leaf_global; }
