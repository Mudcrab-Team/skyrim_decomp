// Source exposure: binary-analysis
// Static174a310, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static174a310;
extern void construct(Static174a310*);
struct Static174a310 {
    Static174a310() { construct(this); }
    ~Static174a310() {}
};
