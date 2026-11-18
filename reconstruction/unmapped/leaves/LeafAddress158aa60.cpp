// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress158aa60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x158aa60 LeafAddress158aa60::Address
#include "LeafAddress158aa60.h"
extern unsigned char leaf_global;
void* LeafAddress158aa60::Address() { return &leaf_global; }
