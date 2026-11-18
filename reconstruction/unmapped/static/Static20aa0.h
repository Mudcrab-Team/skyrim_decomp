// Source exposure: binary-analysis
// Static20aa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20aa0;
extern void construct(Static20aa0*, const Descriptor*);
extern void destroy(Static20aa0*);
struct Static20aa0 {
    void* value;
    Static20aa0() { construct(this, &descriptor); }
    ~Static20aa0() { destroy(this); }
};
