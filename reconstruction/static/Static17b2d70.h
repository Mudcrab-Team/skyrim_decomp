// Source exposure: binary-analysis
// Static17b2d70, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b2d70;
extern void construct(Static17b2d70*);
struct Static17b2d70 {
    Static17b2d70() { construct(this); }
    ~Static17b2d70() {}
};
