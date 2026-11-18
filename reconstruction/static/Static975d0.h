// Source exposure: binary-analysis
// Static975d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static975d0;
extern void construct(Static975d0*, const Descriptor*);
extern void destroy(Static975d0*);
struct Static975d0 {
    void* value;
    Static975d0() { construct(this, &descriptor); }
    ~Static975d0() { destroy(this); }
};
