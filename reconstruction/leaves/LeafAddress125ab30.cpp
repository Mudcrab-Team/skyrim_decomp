// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress125ab30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x125ab30 LeafAddress125ab30::Address
#include "LeafAddress125ab30.h"
extern unsigned char leaf_global;
void* LeafAddress125ab30::Address() { return &leaf_global; }
