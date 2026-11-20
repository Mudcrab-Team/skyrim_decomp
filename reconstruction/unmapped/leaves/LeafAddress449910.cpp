// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress449910, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x449910 LeafAddress449910::Address
#include "LeafAddress449910.h"
extern unsigned char leaf_global;
void* LeafAddress449910::Address() { return &leaf_global; }
