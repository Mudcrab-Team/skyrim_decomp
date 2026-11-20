// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress132860, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x132860 LeafAddress132860::Address
#include "LeafAddress132860.h"
extern unsigned char leaf_global;
void* LeafAddress132860::Address() { return &leaf_global; }
