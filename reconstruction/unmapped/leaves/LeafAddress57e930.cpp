// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress57e930, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x57e930 LeafAddress57e930::Address
#include "LeafAddress57e930.h"
extern unsigned char leaf_global;
void* LeafAddress57e930::Address() { return &leaf_global; }
