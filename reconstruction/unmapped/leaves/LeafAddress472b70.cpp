// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress472b70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x472b70 LeafAddress472b70::Address
#include "LeafAddress472b70.h"
extern unsigned char leaf_global;
void* LeafAddress472b70::Address() { return &leaf_global; }
