// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4963d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4963d0 LeafAddress4963d0::Address
#include "LeafAddress4963d0.h"
extern unsigned char leaf_global;
void* LeafAddress4963d0::Address() { return &leaf_global; }
