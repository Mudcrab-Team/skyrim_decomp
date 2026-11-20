// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12d840, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12d840 LeafAddress12d840::Address
#include "LeafAddress12d840.h"
extern unsigned char leaf_global;
void* LeafAddress12d840::Address() { return &leaf_global; }
