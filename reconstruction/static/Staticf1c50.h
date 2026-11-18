// Source exposure: binary-analysis
// Staticf1c50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf1c50;
extern void construct(Staticf1c50*, const Descriptor*);
extern void destroy(Staticf1c50*);
struct Staticf1c50 {
    void* value;
    Staticf1c50() { construct(this, &descriptor); }
    ~Staticf1c50() { destroy(this); }
};
