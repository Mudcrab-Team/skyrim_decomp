// Source exposure: binary-analysis
// Static20c20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20c20;
extern void construct(Static20c20*, const Descriptor*);
extern void destroy(Static20c20*);
struct Static20c20 {
    void* value;
    Static20c20() { construct(this, &descriptor); }
    ~Static20c20() { destroy(this); }
};
