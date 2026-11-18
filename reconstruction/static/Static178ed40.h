// Source exposure: binary-analysis
// Static178ed40, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static178ed40;
extern void construct(Static178ed40*);
struct Static178ed40 {
    Static178ed40() { construct(this); }
    ~Static178ed40() {}
};
