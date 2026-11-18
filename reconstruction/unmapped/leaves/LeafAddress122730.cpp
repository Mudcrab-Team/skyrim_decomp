// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress122730, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x122730 LeafAddress122730::Address
#include "LeafAddress122730.h"
extern unsigned char leaf_global;
void* LeafAddress122730::Address() { return &leaf_global; }
