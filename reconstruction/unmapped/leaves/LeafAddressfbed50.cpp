// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfbed50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfbed50 BSStripPSysData::GetRTTI
#include "LeafAddressfbed50.h"
extern unsigned char leaf_global;
void* LeafAddressfbed50::Address() { return &leaf_global; }
