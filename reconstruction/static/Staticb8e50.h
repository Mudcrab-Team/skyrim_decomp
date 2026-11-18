// Source exposure: binary-analysis
// Staticb8e50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb8e50;
extern void construct(Staticb8e50*, const Descriptor*);
extern void destroy(Staticb8e50*);
struct Staticb8e50 {
    void* value;
    Staticb8e50() { construct(this, &descriptor); }
    ~Staticb8e50() { destroy(this); }
};
