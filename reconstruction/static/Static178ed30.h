// Source exposure: binary-analysis
// Static178ed30, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static178ed30;
extern void construct(Static178ed30*);
struct Static178ed30 {
    Static178ed30() { construct(this); }
    ~Static178ed30() {}
};
