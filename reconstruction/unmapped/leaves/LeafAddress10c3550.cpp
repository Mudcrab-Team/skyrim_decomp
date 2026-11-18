// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10c3550, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10c3550 LeafAddress10c3550::Address
#include "LeafAddress10c3550.h"
extern unsigned char leaf_global;
void* LeafAddress10c3550::Address() { return &leaf_global; }
