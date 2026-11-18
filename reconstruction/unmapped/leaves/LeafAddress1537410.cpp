// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress1537410, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x1537410 LeafAddress1537410::Address
#include "LeafAddress1537410.h"
extern unsigned char leaf_global;
void* LeafAddress1537410::Address() { return &leaf_global; }
