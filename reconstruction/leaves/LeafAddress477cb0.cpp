// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress477cb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x477cb0 LeafAddress477cb0::Address
#include "LeafAddress477cb0.h"
extern unsigned char leaf_global;
void* LeafAddress477cb0::Address() { return &leaf_global; }
