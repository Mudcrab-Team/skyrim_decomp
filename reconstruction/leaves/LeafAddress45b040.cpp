// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45b040, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45b040 LeafAddress45b040::Address
#include "LeafAddress45b040.h"
extern unsigned char leaf_global;
void* LeafAddress45b040::Address() { return &leaf_global; }
