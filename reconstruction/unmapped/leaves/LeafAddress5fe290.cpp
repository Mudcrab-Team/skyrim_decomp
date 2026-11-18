// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5fe290, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5fe290 LeafAddress5fe290::Address
#include "LeafAddress5fe290.h"
extern unsigned char leaf_global;
void* LeafAddress5fe290::Address() { return &leaf_global; }
