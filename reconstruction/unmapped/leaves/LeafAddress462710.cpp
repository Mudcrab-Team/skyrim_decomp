// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress462710, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x462710 LeafAddress462710::Address
#include "LeafAddress462710.h"
extern unsigned char leaf_global;
void* LeafAddress462710::Address() { return &leaf_global; }
