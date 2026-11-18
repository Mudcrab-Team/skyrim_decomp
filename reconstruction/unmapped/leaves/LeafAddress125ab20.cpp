// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress125ab20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x125ab20 LeafAddress125ab20::Address
#include "LeafAddress125ab20.h"
extern unsigned char leaf_global;
void* LeafAddress125ab20::Address() { return &leaf_global; }
