// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1296800, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1296800 LeafAddress1296800::Address
#include "LeafAddress1296800.h"
extern unsigned char leaf_global;
void* LeafAddress1296800::Address() { return &leaf_global; }
