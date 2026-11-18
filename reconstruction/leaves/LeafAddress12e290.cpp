// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12e290, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12e290 LeafAddress12e290::Address
#include "LeafAddress12e290.h"
extern unsigned char leaf_global;
void* LeafAddress12e290::Address() { return &leaf_global; }
