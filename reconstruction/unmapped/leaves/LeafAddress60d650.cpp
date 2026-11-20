// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress60d650, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x60d650 LeafAddress60d650::Address
#include "LeafAddress60d650.h"
extern unsigned char leaf_global;
void* LeafAddress60d650::Address() { return &leaf_global; }
