// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1002390, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1002390 LeafAddress1002390::Address
#include "LeafAddress1002390.h"
extern unsigned char leaf_global;
void* LeafAddress1002390::Address() { return &leaf_global; }
