// Source exposure: mixed (pinned image, RTTI and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original reconstruction of copyable callable construction.
// SboPayloadCloners2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; wrapper names and capture identities inferred.
// Adapted bodies: none
// CI hash: 0x145e6a0 ??$Clone@UCapture145e6a0@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture145e6a0@bnet_callable@@@bnet_callable@@AEBUCapture145e6a0@2@@Z
// CI hash: 0x145e6e0 ??$Clone@UCapture145e6e0@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture145e6e0@bnet_callable@@@bnet_callable@@AEBUCapture145e6e0@2@@Z
// CI hash: 0x145e720 ??$Clone@UCapture145e720@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture145e720@bnet_callable@@@bnet_callable@@AEBUCapture145e720@2@@Z
// CI hash: 0x145e760 ??$Clone@UCapture145e760@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture145e760@bnet_callable@@@bnet_callable@@AEBUCapture145e760@2@@Z
// CI hash: 0x145e7a0 ??$Clone@UCapture145e7a0@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture145e7a0@bnet_callable@@@bnet_callable@@AEBUCapture145e7a0@2@@Z
// CI hash: 0x147f030 ??$Clone@UCapture147f030@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture147f030@bnet_callable@@@bnet_callable@@AEBUCapture147f030@2@@Z
// CI hash: 0x147f0b0 ??$Clone@UCapture147f0b0@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture147f0b0@bnet_callable@@@bnet_callable@@AEBUCapture147f0b0@2@@Z
// CI hash: 0x147f0f0 ??$Clone@UCapture147f0f0@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture147f0f0@bnet_callable@@@bnet_callable@@AEBUCapture147f0f0@2@@Z
// CI hash: 0x147f130 ??$Clone@UCapture147f130@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture147f130@bnet_callable@@@bnet_callable@@AEBUCapture147f130@2@@Z
// CI hash: 0x147f170 ??$Clone@UCapture147f170@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture147f170@bnet_callable@@@bnet_callable@@AEBUCapture147f170@2@@Z
// CI hash: 0x147f1b0 ??$Clone@UCapture147f1b0@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture147f1b0@bnet_callable@@@bnet_callable@@AEBUCapture147f1b0@2@@Z
// CI hash: 0x147f1f0 ??$Clone@UCapture147f1f0@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture147f1f0@bnet_callable@@@bnet_callable@@AEBUCapture147f1f0@2@@Z
// CI hash: 0x147f230 ??$Clone@UCapture147f230@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture147f230@bnet_callable@@@bnet_callable@@AEBUCapture147f230@2@@Z
// CI hash: 0x147f270 ??$Clone@UCapture147f270@bnet_callable@@@SboPayloadCloners2@@SAPEAV?$CopyableCallable@UCapture147f270@bnet_callable@@@bnet_callable@@AEBUCapture147f270@2@@Z
// 0x145e6a0 SboPayloadCloners2::Clone
// 0x145e6e0 SboPayloadCloners2::Clone
// 0x145e720 SboPayloadCloners2::Clone
// 0x145e760 SboPayloadCloners2::Clone
// 0x145e7a0 SboPayloadCloners2::Clone
// 0x147f030 SboPayloadCloners2::Clone
// 0x147f0b0 SboPayloadCloners2::Clone
// 0x147f0f0 SboPayloadCloners2::Clone
// 0x147f130 SboPayloadCloners2::Clone
// 0x147f170 SboPayloadCloners2::Clone
// 0x147f1b0 SboPayloadCloners2::Clone
// 0x147f1f0 SboPayloadCloners2::Clone
// 0x147f230 SboPayloadCloners2::Clone
// 0x147f270 SboPayloadCloners2::Clone
#include "SboPayloadCloners2.h"
#include <new>

template <class Capture>
bnet_callable::CopyableCallable<Capture>* SboPayloadCloners2::Clone(const Capture& source)
{
    using Callable = bnet_callable::CopyableCallable<Capture>;
    void* storage = gAllocFn_3356368(sizeof(Callable));
    return new (storage) Callable(source);
}

template bnet_callable::CopyableCallable<bnet_callable::Capture145e6a0>* SboPayloadCloners2::Clone<bnet_callable::Capture145e6a0>(const bnet_callable::Capture145e6a0&);
template bnet_callable::CopyableCallable<bnet_callable::Capture145e6e0>* SboPayloadCloners2::Clone<bnet_callable::Capture145e6e0>(const bnet_callable::Capture145e6e0&);
template bnet_callable::CopyableCallable<bnet_callable::Capture145e720>* SboPayloadCloners2::Clone<bnet_callable::Capture145e720>(const bnet_callable::Capture145e720&);
template bnet_callable::CopyableCallable<bnet_callable::Capture145e760>* SboPayloadCloners2::Clone<bnet_callable::Capture145e760>(const bnet_callable::Capture145e760&);
template bnet_callable::CopyableCallable<bnet_callable::Capture145e7a0>* SboPayloadCloners2::Clone<bnet_callable::Capture145e7a0>(const bnet_callable::Capture145e7a0&);
template bnet_callable::CopyableCallable<bnet_callable::Capture147f030>* SboPayloadCloners2::Clone<bnet_callable::Capture147f030>(const bnet_callable::Capture147f030&);
template bnet_callable::CopyableCallable<bnet_callable::Capture147f0b0>* SboPayloadCloners2::Clone<bnet_callable::Capture147f0b0>(const bnet_callable::Capture147f0b0&);
template bnet_callable::CopyableCallable<bnet_callable::Capture147f0f0>* SboPayloadCloners2::Clone<bnet_callable::Capture147f0f0>(const bnet_callable::Capture147f0f0&);
template bnet_callable::CopyableCallable<bnet_callable::Capture147f130>* SboPayloadCloners2::Clone<bnet_callable::Capture147f130>(const bnet_callable::Capture147f130&);
template bnet_callable::CopyableCallable<bnet_callable::Capture147f170>* SboPayloadCloners2::Clone<bnet_callable::Capture147f170>(const bnet_callable::Capture147f170&);
template bnet_callable::CopyableCallable<bnet_callable::Capture147f1b0>* SboPayloadCloners2::Clone<bnet_callable::Capture147f1b0>(const bnet_callable::Capture147f1b0&);
template bnet_callable::CopyableCallable<bnet_callable::Capture147f1f0>* SboPayloadCloners2::Clone<bnet_callable::Capture147f1f0>(const bnet_callable::Capture147f1f0&);
template bnet_callable::CopyableCallable<bnet_callable::Capture147f230>* SboPayloadCloners2::Clone<bnet_callable::Capture147f230>(const bnet_callable::Capture147f230&);
template bnet_callable::CopyableCallable<bnet_callable::Capture147f270>* SboPayloadCloners2::Clone<bnet_callable::Capture147f270>(const bnet_callable::Capture147f270&);
