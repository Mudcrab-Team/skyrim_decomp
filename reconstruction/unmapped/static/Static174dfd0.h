// Source exposure: binary-analysis
// Static174dfd0, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static174dfd0;
extern void construct(Static174dfd0*);
struct Static174dfd0 {
    Static174dfd0() { construct(this); }
    ~Static174dfd0() {}
};
