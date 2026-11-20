// Source exposure: binary-analysis
// Static20bc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20bc0;
extern void construct(Static20bc0*, const Descriptor*);
extern void destroy(Static20bc0*);
struct Static20bc0 {
    void* value;
    Static20bc0() { construct(this, &descriptor); }
    ~Static20bc0() { destroy(this); }
};
