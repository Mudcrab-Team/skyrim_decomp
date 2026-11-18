// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressee1310, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xee1310 LeafAddressee1310::Address
#include "LeafAddressee1310.h"
extern unsigned char leaf_global;
void* LeafAddressee1310::Address() { return &leaf_global; }
