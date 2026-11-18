// Source exposure: binary-analysis
// Static1df20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1df20;
extern void construct(Static1df20*, const Descriptor*);
extern void destroy(Static1df20*);
struct Static1df20 {
    void* value;
    Static1df20() { construct(this, &descriptor); }
    ~Static1df20() { destroy(this); }
};
