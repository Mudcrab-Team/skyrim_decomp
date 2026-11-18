// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress143cd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x143cd0 LeafAddress143cd0::Address
#include "LeafAddress143cd0.h"
extern unsigned char leaf_global;
void* LeafAddress143cd0::Address() { return &leaf_global; }
