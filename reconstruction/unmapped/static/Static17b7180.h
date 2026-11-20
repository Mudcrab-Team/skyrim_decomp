// Source exposure: binary-analysis
// Static17b7180, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b7180;
extern void construct(Static17b7180*);
struct Static17b7180 {
    Static17b7180() { construct(this); }
    ~Static17b7180() {}
};
