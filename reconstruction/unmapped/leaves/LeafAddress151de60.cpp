// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress151de60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x151de60 LeafAddress151de60::Address
#include "LeafAddress151de60.h"
extern unsigned char leaf_global;
void* LeafAddress151de60::Address() { return &leaf_global; }
