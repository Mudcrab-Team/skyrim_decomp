// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress479290, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x479290 LeafAddress479290::Address
#include "LeafAddress479290.h"
extern unsigned char leaf_global;
void* LeafAddress479290::Address() { return &leaf_global; }
