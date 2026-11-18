// Source exposure: binary-analysis
// Staticb3d70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb3d70;
extern void construct(Staticb3d70*, const Descriptor*);
extern void destroy(Staticb3d70*);
struct Staticb3d70 {
    void* value;
    Staticb3d70() { construct(this, &descriptor); }
    ~Staticb3d70() { destroy(this); }
};
