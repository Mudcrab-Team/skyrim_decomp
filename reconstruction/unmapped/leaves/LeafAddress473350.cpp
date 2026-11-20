// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress473350, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x473350 LeafAddress473350::Address
#include "LeafAddress473350.h"
extern unsigned char leaf_global;
void* LeafAddress473350::Address() { return &leaf_global; }
