// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress48d2f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x48d2f0 LeafAddress48d2f0::Address
#include "LeafAddress48d2f0.h"
extern unsigned char leaf_global;
void* LeafAddress48d2f0::Address() { return &leaf_global; }
