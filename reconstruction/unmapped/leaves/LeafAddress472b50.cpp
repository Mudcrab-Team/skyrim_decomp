// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress472b50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x472b50 LeafAddress472b50::Address
#include "LeafAddress472b50.h"
extern unsigned char leaf_global;
void* LeafAddress472b50::Address() { return &leaf_global; }
