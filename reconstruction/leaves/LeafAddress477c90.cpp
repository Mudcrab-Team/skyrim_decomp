// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress477c90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x477c90 LeafAddress477c90::Address
#include "LeafAddress477c90.h"
extern unsigned char leaf_global;
void* LeafAddress477c90::Address() { return &leaf_global; }
