// Source exposure: binary-analysis
// Static1b130, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b130;
extern void construct(Static1b130*, const Descriptor*);
extern void destroy(Static1b130*);
struct Static1b130 {
    void* value;
    Static1b130() { construct(this, &descriptor); }
    ~Static1b130() { destroy(this); }
};
