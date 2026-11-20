// Source exposure: binary-analysis
// Static20da0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20da0;
extern void construct(Static20da0*, const Descriptor*);
extern void destroy(Static20da0*);
struct Static20da0 {
    void* value;
    Static20da0() { construct(this, &descriptor); }
    ~Static20da0() { destroy(this); }
};
