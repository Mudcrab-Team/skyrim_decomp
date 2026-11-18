// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10ac930, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10ac930 LeafAddress10ac930::Address
#include "LeafAddress10ac930.h"
extern unsigned char leaf_global;
void* LeafAddress10ac930::Address() { return &leaf_global; }
