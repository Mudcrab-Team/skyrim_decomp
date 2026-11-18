// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress125ab40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x125ab40 LeafAddress125ab40::Address
#include "LeafAddress125ab40.h"
extern unsigned char leaf_global;
void* LeafAddress125ab40::Address() { return &leaf_global; }
