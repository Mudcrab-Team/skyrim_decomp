// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x31b530 BGSColorForm::InitializeData
#include "BGSColorForm.h"

void BGSColorForm::InitializeData()
{
    color.value = 0;
    flags = 0;
}

void BGSColorForm::ClearData()
{
    color.value = 0;
    flags = 0;
}
