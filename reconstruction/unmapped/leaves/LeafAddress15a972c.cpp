// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress15a972c, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x15a972c LeafAddress15a972c::Address
#include "LeafAddress15a972c.h"
extern unsigned char leaf_global;
void* LeafAddress15a972c::Address() { return &leaf_global; }
