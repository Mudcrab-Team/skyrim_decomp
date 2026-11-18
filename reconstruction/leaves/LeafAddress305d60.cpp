// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress305d60, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x305d60 LeafAddress305d60::Address
#include "LeafAddress305d60.h"
extern unsigned char leaf_global;
void* LeafAddress305d60::Address() { return &leaf_global; }
