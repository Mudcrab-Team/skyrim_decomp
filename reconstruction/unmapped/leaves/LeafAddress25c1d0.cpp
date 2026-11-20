// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress25c1d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x25c1d0 LeafAddress25c1d0::Address
#include "LeafAddress25c1d0.h"
extern unsigned char leaf_global;
void* LeafAddress25c1d0::Address() { return &leaf_global; }
