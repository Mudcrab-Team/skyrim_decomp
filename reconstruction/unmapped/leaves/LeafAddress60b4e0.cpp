// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress60b4e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x60b4e0 LeafAddress60b4e0::Address
#include "LeafAddress60b4e0.h"
extern unsigned char leaf_global;
void* LeafAddress60b4e0::Address() { return &leaf_global; }
