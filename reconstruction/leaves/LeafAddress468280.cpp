// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress468280, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x468280 LeafAddress468280::Address
#include "LeafAddress468280.h"
extern unsigned char leaf_global;
void* LeafAddress468280::Address() { return &leaf_global; }
