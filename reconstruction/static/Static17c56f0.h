// Source exposure: binary-analysis
// Static17c56f0, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17c56f0;
extern void construct(Static17c56f0*);
struct Static17c56f0 {
    Static17c56f0() { construct(this); }
    ~Static17c56f0() {}
};
