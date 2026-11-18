// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CommonLibSSE-NG (MIT), and no external implementation body or layout is copied.
// Source exposure: binary-analysis. Drafted by Taylor Turner, assisted by claude-sonnet-5-5.
// 0xef6180 BSDismemberSkinInstance::RegisterStreamables
#include "BSDismemberSkinInstance.h"

bool BSDismemberSkinInstance::RegisterStreamables(NiStream& a_stream)
{
    return NiSkinInstance::RegisterStreamables(a_stream) != false;
}
