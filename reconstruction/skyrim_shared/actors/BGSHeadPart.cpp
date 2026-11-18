// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x391020 BGSHeadPart::GetFormEditorID
// 0x391210 BGSHeadPart::SetFormEditorID
#include "BGSHeadPart.h"

const char* BGSHeadPart::GetFormEditorID() const
{
    return formEditorID.c_str();
}

bool BGSHeadPart::SetFormEditorID(const char* a_str)
{
    formEditorID = a_str;
    return true;
}
