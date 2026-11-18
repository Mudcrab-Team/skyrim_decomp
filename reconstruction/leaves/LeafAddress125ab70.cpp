// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress125ab70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x125ab70 LeafAddress125ab70::Address
#include "LeafAddress125ab70.h"
extern unsigned char leaf_global;
void* LeafAddress125ab70::Address() { return &leaf_global; }
