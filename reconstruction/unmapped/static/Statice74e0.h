// Source exposure: binary-analysis
// Statice74e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice74e0;
extern void construct(Statice74e0*, const Descriptor*);
extern void destroy(Statice74e0*);
struct Statice74e0 {
    void* value;
    Statice74e0() { construct(this, &descriptor); }
    ~Statice74e0() { destroy(this); }
};
