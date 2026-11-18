// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress464600, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x464600 LeafAddress464600::Address
#include "LeafAddress464600.h"
extern unsigned char leaf_global;
void* LeafAddress464600::Address() { return &leaf_global; }
