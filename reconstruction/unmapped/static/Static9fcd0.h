// Source exposure: binary-analysis
// Static9fcd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fcd0;
extern void construct(Static9fcd0*, const Descriptor*);
extern void destroy(Static9fcd0*);
struct Static9fcd0 {
    void* value;
    Static9fcd0() { construct(this, &descriptor); }
    ~Static9fcd0() { destroy(this); }
};
