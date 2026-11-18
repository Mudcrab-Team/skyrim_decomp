// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress125ab10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x125ab10 LeafAddress125ab10::Address
#include "LeafAddress125ab10.h"
extern unsigned char leaf_global;
void* LeafAddress125ab10::Address() { return &leaf_global; }
