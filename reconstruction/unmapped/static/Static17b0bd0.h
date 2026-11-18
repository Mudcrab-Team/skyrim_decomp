// Source exposure: binary-analysis
// Static17b0bd0, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b0bd0;
extern void construct(Static17b0bd0*);
struct Static17b0bd0 {
    Static17b0bd0() { construct(this); }
    ~Static17b0bd0() {}
};
