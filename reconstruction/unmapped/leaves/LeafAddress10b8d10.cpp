// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10b8d10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10b8d10 LeafAddress10b8d10::Address
#include "LeafAddress10b8d10.h"
extern unsigned char leaf_global;
void* LeafAddress10b8d10::Address() { return &leaf_global; }
