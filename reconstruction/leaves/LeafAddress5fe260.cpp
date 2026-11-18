// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5fe260, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5fe260 LeafAddress5fe260::Address
#include "LeafAddress5fe260.h"
extern unsigned char leaf_global;
void* LeafAddress5fe260::Address() { return &leaf_global; }
