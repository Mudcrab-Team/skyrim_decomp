// Source exposure: binary-analysis
// Static214f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static214f0;
extern void construct(Static214f0*, const Descriptor*);
extern void destroy(Static214f0*);
struct Static214f0 {
    void* value;
    Static214f0() { construct(this, &descriptor); }
    ~Static214f0() { destroy(this); }
};
