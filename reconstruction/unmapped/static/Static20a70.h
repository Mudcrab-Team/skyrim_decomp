// Source exposure: binary-analysis
// Static20a70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20a70;
extern void construct(Static20a70*, const Descriptor*);
extern void destroy(Static20a70*);
struct Static20a70 {
    void* value;
    Static20a70() { construct(this, &descriptor); }
    ~Static20a70() { destroy(this); }
};
