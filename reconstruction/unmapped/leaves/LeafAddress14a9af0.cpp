// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress14a9af0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x14a9af0 LeafAddress14a9af0::Address
#include "LeafAddress14a9af0.h"
extern unsigned char leaf_global;
void* LeafAddress14a9af0::Address() { return &leaf_global; }
