// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress15872d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x15872d0 LeafAddress15872d0::Address
#include "LeafAddress15872d0.h"
extern unsigned char leaf_global;
void* LeafAddress15872d0::Address() { return &leaf_global; }
