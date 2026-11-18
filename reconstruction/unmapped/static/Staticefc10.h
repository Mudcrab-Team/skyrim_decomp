// Source exposure: binary-analysis
// Staticefc10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefc10;
extern void construct(Staticefc10*, const Descriptor*);
extern void destroy(Staticefc10*);
struct Staticefc10 {
    void* value;
    Staticefc10() { construct(this, &descriptor); }
    ~Staticefc10() { destroy(this); }
};
