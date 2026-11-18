// Source exposure: binary-analysis
// Staticbafb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbafb0;
extern void construct(Staticbafb0*, const Descriptor*);
extern void destroy(Staticbafb0*);
struct Staticbafb0 {
    void* value;
    Staticbafb0() { construct(this, &descriptor); }
    ~Staticbafb0() { destroy(this); }
};
