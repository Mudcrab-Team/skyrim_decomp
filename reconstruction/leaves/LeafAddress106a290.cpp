// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress106a290, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x106a290 LeafAddress106a290::Address
#include "LeafAddress106a290.h"
extern unsigned char leaf_global;
void* LeafAddress106a290::Address() { return &leaf_global; }
