// Source exposure: binary-analysis
// Static108330, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108330;
extern void construct(Static108330*, const Descriptor*);
extern void destroy(Static108330*);
struct Static108330 {
    void* value;
    Static108330() { construct(this, &descriptor); }
    ~Static108330() { destroy(this); }
};
