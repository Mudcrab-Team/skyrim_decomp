// Source exposure: binary-analysis
// Static153d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static153d0;
extern void construct(Static153d0*, const Descriptor*);
extern void destroy(Static153d0*);
struct Static153d0 {
    void* value;
    Static153d0() { construct(this, &descriptor); }
    ~Static153d0() { destroy(this); }
};
