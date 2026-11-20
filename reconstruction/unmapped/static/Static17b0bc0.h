// Source exposure: binary-analysis
// Static17b0bc0, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b0bc0;
extern void construct(Static17b0bc0*);
struct Static17b0bc0 {
    Static17b0bc0() { construct(this); }
    ~Static17b0bc0() {}
};
