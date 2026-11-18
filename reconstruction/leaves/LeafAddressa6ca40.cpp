// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressa6ca40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xa6ca40 LeafAddressa6ca40::Address
#include "LeafAddressa6ca40.h"
extern unsigned char leaf_global;
void* LeafAddressa6ca40::Address() { return &leaf_global; }
