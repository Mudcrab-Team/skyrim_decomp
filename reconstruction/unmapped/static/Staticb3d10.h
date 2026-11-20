// Source exposure: binary-analysis
// Staticb3d10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb3d10;
extern void construct(Staticb3d10*, const Descriptor*);
extern void destroy(Staticb3d10*);
struct Staticb3d10 {
    void* value;
    Staticb3d10() { construct(this, &descriptor); }
    ~Staticb3d10() { destroy(this); }
};
