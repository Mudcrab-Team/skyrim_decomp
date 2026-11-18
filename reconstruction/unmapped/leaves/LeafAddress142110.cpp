// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress142110, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x142110 LeafAddress142110::Address
#include "LeafAddress142110.h"
extern unsigned char leaf_global;
void* LeafAddress142110::Address() { return &leaf_global; }
