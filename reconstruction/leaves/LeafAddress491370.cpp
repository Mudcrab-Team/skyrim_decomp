// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress491370, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x491370 LeafAddress491370::Address
#include "LeafAddress491370.h"
extern unsigned char leaf_global;
void* LeafAddress491370::Address() { return &leaf_global; }
