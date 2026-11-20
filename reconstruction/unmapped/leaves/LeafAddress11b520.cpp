// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress11b520, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x11b520 LeafAddress11b520::Address
#include "LeafAddress11b520.h"
extern unsigned char leaf_global;
void* LeafAddress11b520::Address() { return &leaf_global; }
