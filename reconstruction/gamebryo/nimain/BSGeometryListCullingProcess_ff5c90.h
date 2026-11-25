// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSGeometryListCullingProcess, SubmitCollectedGeometry, NiCullingProcess layout objectArray and BSCullingProcess::SubmitCullResults: CRASHLOGGER_PDB(59818@2026.10.24)
// useList and flag: GUESS(low) STANDIN
#pragma once

#include "generated/crashlogger_pdb/types/NiCullingProcess.h"
#include "generated/crashlogger_pdb/types/BSTArray_RE__NiPointer_RE__NiAVObject_f418c101.h"


using ObjectArray = BSTArray_RE__NiPointer_RE__NiAVObject_f418c101;
struct BSCullingProcess : NiCullingProcess {
    void SubmitCullResults(ObjectArray& objects, NiCamera* camera, bool useList, bool flag);
};
struct BSGeometryListCullingProcess : NiCullingProcess {
    ObjectArray objectArray;
    void SubmitCollectedGeometry(BSCullingProcess& submitter, bool flag);
};
