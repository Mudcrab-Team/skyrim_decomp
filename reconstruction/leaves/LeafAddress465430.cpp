// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress465430, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x465430 LeafAddress465430::Address
#include "LeafAddress465430.h"
extern unsigned char leaf_global;
void* LeafAddress465430::Address() { return &leaf_global; }
