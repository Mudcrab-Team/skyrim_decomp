// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress737f30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x737f30 LeafAddress737f30::Address
#include "LeafAddress737f30.h"
extern unsigned char leaf_global;
void* LeafAddress737f30::Address() { return &leaf_global; }
