// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress3a3020, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x3a3020 BGSRefAlias::QType
#include "LeafAddress3a3020.h"
extern unsigned char leaf_global;
void* LeafAddress3a3020::Address() { return &leaf_global; }
