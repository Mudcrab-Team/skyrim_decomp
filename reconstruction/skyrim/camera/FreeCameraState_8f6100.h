// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: minimal community declarations; external event slots have unknown semantic names.
// FreeCameraState, CanProcess, InputEvent, HasIDCode, QUserEvent, BSFixedString, UserEvents, run: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InputEvent, BSFixedString, UserEvents: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// userEvents, additionalEvent1, additionalEvent2, additionalEvent3, additionalEvent4, additionalEvent5: GUESS(low); private reference slots only
#pragma once
#include <cstddef>

struct BSFixedString { const char* data; };
class InputEvent {
public:
    virtual ~InputEvent();
    virtual bool HasIDCode() const;
    virtual const BSFixedString& QUserEvent() const;
};
struct UserEvents {
    unsigned char _pad00[0xb0];
    const char* run;
};
extern UserEvents* userEvents;
extern const char* additionalEvent1;
extern const char* additionalEvent2;
extern const char* additionalEvent3;
extern const char* additionalEvent4;
extern const char* additionalEvent5;
class FreeCameraState {
public:
    // 0x8f6100 FreeCameraState::CanProcess
    bool CanProcess(InputEvent* event);
};
static_assert(offsetof(UserEvents, run) == 0xb0, "run offset");
