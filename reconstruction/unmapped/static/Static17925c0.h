// Source exposure: binary-analysis
// Static17925c0, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17925c0;
extern void construct(Static17925c0*);
struct Static17925c0 {
    Static17925c0() { construct(this); }
    ~Static17925c0() {}
};
