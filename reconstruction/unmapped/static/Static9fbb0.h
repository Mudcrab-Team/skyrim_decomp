// Source exposure: binary-analysis
// Static9fbb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fbb0;
extern void construct(Static9fbb0*, const Descriptor*);
extern void destroy(Static9fbb0*);
struct Static9fbb0 {
    void* value;
    Static9fbb0() { construct(this, &descriptor); }
    ~Static9fbb0() { destroy(this); }
};
