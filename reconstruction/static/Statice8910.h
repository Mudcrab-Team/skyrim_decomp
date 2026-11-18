// Source exposure: binary-analysis
// Statice8910, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice8910;
extern void construct(Statice8910*, const Descriptor*);
extern void destroy(Statice8910*);
struct Statice8910 {
    void* value;
    Statice8910() { construct(this, &descriptor); }
    ~Statice8910() { destroy(this); }
};
