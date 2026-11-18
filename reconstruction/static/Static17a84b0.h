// Source exposure: binary-analysis
// Static17a84b0, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17a84b0;
extern void construct(Static17a84b0*);
struct Static17a84b0 {
    Static17a84b0() { construct(this); }
    ~Static17a84b0() {}
};
