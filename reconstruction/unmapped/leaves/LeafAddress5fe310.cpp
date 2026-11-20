// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5fe310, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5fe310 LeafAddress5fe310::Address
#include "LeafAddress5fe310.h"
extern unsigned char leaf_global;
void* LeafAddress5fe310::Address() { return &leaf_global; }
