// Source exposure: binary-analysis
// Static178ed20, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static178ed20;
extern void construct(Static178ed20*);
struct Static178ed20 {
    Static178ed20() { construct(this); }
    ~Static178ed20() {}
};
