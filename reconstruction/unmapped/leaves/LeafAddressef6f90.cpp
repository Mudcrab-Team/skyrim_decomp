// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressef6f90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xef6f90 BSDismemberSkinInstance::GetRTTI
#include "LeafAddressef6f90.h"
extern unsigned char leaf_global;
void* LeafAddressef6f90::Address() { return &leaf_global; }
