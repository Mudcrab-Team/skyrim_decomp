// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x328688 BGSMusicType::dtor
// 0x328550 BGSMusicType::GetFormEditorID
// 0x328570 BGSMusicType::SetFormEditorID
// 0x327e40 BGSMusicType::DoPause
#include "BGSMusicType.h"

// The constructor is not compared: it is defined so that this unit emits the vftables and with
// them the destructor thunk.
BGSMusicType::BGSMusicType()
{
}

BGSMusicType::~BGSMusicType()
{
}

const char* BGSMusicType::GetFormEditorID() const
{
    return formEditorID.c_str();
}

bool BGSMusicType::SetFormEditorID(const char* a_str)
{
    formEditorID = a_str;
    return true;
}

void BGSMusicType::DoPause()
{
    tracks[currentTrackIndex]->DoPause();
    typeStatus = 2;
}
