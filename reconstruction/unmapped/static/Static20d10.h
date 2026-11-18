// Source exposure: binary-analysis
// Static20d10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20d10;
extern void construct(Static20d10*, const Descriptor*);
extern void destroy(Static20d10*);
struct Static20d10 {
    void* value;
    Static20d10() { construct(this, &descriptor); }
    ~Static20d10() { destroy(this); }
};
