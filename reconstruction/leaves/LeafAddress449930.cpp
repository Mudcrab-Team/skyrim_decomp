// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress449930, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x449930 LeafAddress449930::Address
#include "LeafAddress449930.h"
extern unsigned char leaf_global;
void* LeafAddress449930::Address() { return &leaf_global; }
