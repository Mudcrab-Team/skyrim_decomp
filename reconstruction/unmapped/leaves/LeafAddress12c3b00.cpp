// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12c3b00, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12c3b00 LeafAddress12c3b00::Address
#include "LeafAddress12c3b00.h"
extern unsigned char leaf_global;
void* LeafAddress12c3b00::Address() { return &leaf_global; }
