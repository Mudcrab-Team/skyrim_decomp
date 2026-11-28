// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xf15e40 NiParticleMeshes::SetSelectiveUpdateFlags
// CI hash: 0xf15e40 ?SetSelectiveUpdateFlags@NiParticleMeshes@@QEAAXAEA_N_N0@Z
#include "NiParticleMeshes_f15e40.h"

// Propagate selective-update flags to the base particle system and particle mesh root, clearing rigidity.
// The CrashLogger name carries an address suffix, which is dropped here.
void NiParticleMeshes::SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid)
{
    (void)a_selectiveUpdateTransforms;
    NiParticles::SetSelectiveUpdateFlags(a_selectiveUpdate, true, a_rigid);
    NiAVObject* meshRoot = modelData->meshRoot;
    meshRoot->SetSelectiveUpdateFlags(a_selectiveUpdate, true, a_rigid);
    a_rigid = false;
    meshRoot->flags &= ~0x10u;
}
