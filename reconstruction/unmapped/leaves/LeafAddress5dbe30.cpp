// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5dbe30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5dbe30 LeafAddress5dbe30::Address
#include "LeafAddress5dbe30.h"
extern unsigned char leaf_global;
void* LeafAddress5dbe30::Address() { return &leaf_global; }
