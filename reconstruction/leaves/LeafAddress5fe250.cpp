// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5fe250, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5fe250 LeafAddress5fe250::Address
#include "LeafAddress5fe250.h"
extern unsigned char leaf_global;
void* LeafAddress5fe250::Address() { return &leaf_global; }
