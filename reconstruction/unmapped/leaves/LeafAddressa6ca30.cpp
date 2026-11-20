// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressa6ca30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xa6ca30 LeafAddressa6ca30::Address
#include "LeafAddressa6ca30.h"
extern unsigned char leaf_global;
void* LeafAddressa6ca30::Address() { return &leaf_global; }
