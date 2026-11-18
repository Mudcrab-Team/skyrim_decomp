// Source exposure: binary-analysis
// Static9ecf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ecf0;
extern void construct(Static9ecf0*, const Descriptor*);
extern void destroy(Static9ecf0*);
struct Static9ecf0 {
    void* value;
    Static9ecf0() { construct(this, &descriptor); }
    ~Static9ecf0() { destroy(this); }
};
