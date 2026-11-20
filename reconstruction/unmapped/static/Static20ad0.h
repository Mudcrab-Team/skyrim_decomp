// Source exposure: binary-analysis
// Static20ad0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20ad0;
extern void construct(Static20ad0*, const Descriptor*);
extern void destroy(Static20ad0*);
struct Static20ad0 {
    void* value;
    Static20ad0() { construct(this, &descriptor); }
    ~Static20ad0() { destroy(this); }
};
