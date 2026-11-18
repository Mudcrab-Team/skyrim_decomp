// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressa6ca20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xa6ca20 LeafAddressa6ca20::Address
#include "LeafAddressa6ca20.h"
extern unsigned char leaf_global;
void* LeafAddressa6ca20::Address() { return &leaf_global; }
