// Source exposure: binary-analysis
// Static20d70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20d70;
extern void construct(Static20d70*, const Descriptor*);
extern void destroy(Static20d70*);
struct Static20d70 {
    void* value;
    Static20d70() { construct(this, &descriptor); }
    ~Static20d70() { destroy(this); }
};
