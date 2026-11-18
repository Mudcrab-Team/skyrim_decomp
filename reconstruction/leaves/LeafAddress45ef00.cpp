// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45ef00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45ef00 LeafAddress45ef00::Address
#include "LeafAddress45ef00.h"
extern unsigned char leaf_global;
void* LeafAddress45ef00::Address() { return &leaf_global; }
