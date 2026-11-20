// Source exposure: binary-analysis
// Statice8880, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice8880;
extern void construct(Statice8880*, const Descriptor*);
extern void destroy(Statice8880*);
struct Statice8880 {
    void* value;
    Statice8880() { construct(this, &descriptor); }
    ~Statice8880() { destroy(this); }
};
