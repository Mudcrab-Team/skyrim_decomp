// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress52dde0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x52dde0 LeafAddress52dde0::Address
#include "LeafAddress52dde0.h"
extern unsigned char leaf_global;
void* LeafAddress52dde0::Address() { return &leaf_global; }
