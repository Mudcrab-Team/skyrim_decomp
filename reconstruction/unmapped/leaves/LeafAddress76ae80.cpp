// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress76ae80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x76ae80 LeafAddress76ae80::Address
#include "LeafAddress76ae80.h"
extern unsigned char leaf_global;
void* LeafAddress76ae80::Address() { return &leaf_global; }
