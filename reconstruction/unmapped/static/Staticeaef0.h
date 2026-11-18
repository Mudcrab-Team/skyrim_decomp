// Source exposure: binary-analysis
// Staticeaef0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticeaef0;
extern void construct(Staticeaef0*, const Descriptor*);
extern void destroy(Staticeaef0*);
struct Staticeaef0 {
    void* value;
    Staticeaef0() { construct(this, &descriptor); }
    ~Staticeaef0() { destroy(this); }
};
