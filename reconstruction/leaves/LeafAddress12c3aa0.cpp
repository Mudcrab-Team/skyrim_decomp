// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12c3aa0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12c3aa0 LeafAddress12c3aa0::Address
#include "LeafAddress12c3aa0.h"
extern unsigned char leaf_global;
void* LeafAddress12c3aa0::Address() { return &leaf_global; }
