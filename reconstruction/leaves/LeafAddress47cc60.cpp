// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress47cc60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x47cc60 LeafAddress47cc60::Address
#include "LeafAddress47cc60.h"
extern unsigned char leaf_global;
void* LeafAddress47cc60::Address() { return &leaf_global; }
