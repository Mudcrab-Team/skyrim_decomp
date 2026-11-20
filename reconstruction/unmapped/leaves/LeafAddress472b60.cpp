// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress472b60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x472b60 LeafAddress472b60::Address
#include "LeafAddress472b60.h"
extern unsigned char leaf_global;
void* LeafAddress472b60::Address() { return &leaf_global; }
