// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress213c40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x213c40 LeafAddress213c40::Address
#include "LeafAddress213c40.h"
extern unsigned char leaf_global;
void* LeafAddress213c40::Address() { return &leaf_global; }
