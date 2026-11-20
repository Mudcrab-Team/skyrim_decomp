// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x321c34 BGSMaterialObject::dtor
// 0x321740 BGSMaterialObject::EnsureLoaded
#include "BGSMaterialObject.h"

// The constructor is not compared: it is defined so that this unit emits the vftables and with
// them the destructor thunk.
BGSMaterialObject::BGSMaterialObject()
{
}

BGSMaterialObject::~BGSMaterialObject()
{
}

void BGSMaterialObject::EnsureLoaded()
{
    if (properties.empty() && !fileData.empty()) {
        LoadFileData();
    }
}
