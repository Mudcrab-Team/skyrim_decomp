// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45af50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45af50 LeafAddress45af50::Address
#include "LeafAddress45af50.h"
extern unsigned char leaf_global;
void* LeafAddress45af50::Address() { return &leaf_global; }
