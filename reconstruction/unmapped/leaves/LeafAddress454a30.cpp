// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress454a30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x454a30 LeafAddress454a30::Address
#include "LeafAddress454a30.h"
extern unsigned char leaf_global;
void* LeafAddress454a30::Address() { return &leaf_global; }
