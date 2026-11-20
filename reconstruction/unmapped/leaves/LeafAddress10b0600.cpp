// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10b0600, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10b0600 LeafAddress10b0600::Address
#include "LeafAddress10b0600.h"
extern unsigned char leaf_global;
void* LeafAddress10b0600::Address() { return &leaf_global; }
