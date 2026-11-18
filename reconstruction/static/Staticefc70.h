// Source exposure: binary-analysis
// Staticefc70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefc70;
extern void construct(Staticefc70*, const Descriptor*);
extern void destroy(Staticefc70*);
struct Staticefc70 {
    void* value;
    Staticefc70() { construct(this, &descriptor); }
    ~Staticefc70() { destroy(this); }
};
