// Source exposure: binary-analysis
// Static20cb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20cb0;
extern void construct(Static20cb0*, const Descriptor*);
extern void destroy(Static20cb0*);
struct Static20cb0 {
    void* value;
    Static20cb0() { construct(this, &descriptor); }
    ~Static20cb0() { destroy(this); }
};
