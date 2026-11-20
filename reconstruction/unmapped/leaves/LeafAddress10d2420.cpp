// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10d2420, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10d2420 LeafAddress10d2420::Address
#include "LeafAddress10d2420.h"
extern unsigned char leaf_global;
void* LeafAddress10d2420::Address() { return &leaf_global; }
