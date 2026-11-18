// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10b44c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10b44c0 LeafAddress10b44c0::Address
#include "LeafAddress10b44c0.h"
extern unsigned char leaf_global;
void* LeafAddress10b44c0::Address() { return &leaf_global; }
