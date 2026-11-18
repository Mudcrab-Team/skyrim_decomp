// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress605610, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x605610 LeafAddress605610::Address
#include "LeafAddress605610.h"
extern unsigned char leaf_global;
void* LeafAddress605610::Address() { return &leaf_global; }
