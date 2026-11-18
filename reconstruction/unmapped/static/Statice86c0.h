// Source exposure: binary-analysis
// Statice86c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice86c0;
extern void construct(Statice86c0*, const Descriptor*);
extern void destroy(Statice86c0*);
struct Statice86c0 {
    void* value;
    Statice86c0() { construct(this, &descriptor); }
    ~Statice86c0() { destroy(this); }
};
