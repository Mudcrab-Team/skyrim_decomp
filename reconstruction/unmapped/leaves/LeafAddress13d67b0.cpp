// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress13d67b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x13d67b0 LeafAddress13d67b0::Address
#include "LeafAddress13d67b0.h"
extern unsigned char leaf_global;
void* LeafAddress13d67b0::Address() { return &leaf_global; }
