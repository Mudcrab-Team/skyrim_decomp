// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress13f340, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x13f340 LeafAddress13f340::Address
#include "LeafAddress13f340.h"
extern unsigned char leaf_global;
void* LeafAddress13f340::Address() { return &leaf_global; }
