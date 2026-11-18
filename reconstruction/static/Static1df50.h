// Source exposure: binary-analysis
// Static1df50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1df50;
extern void construct(Static1df50*, const Descriptor*);
extern void destroy(Static1df50*);
struct Static1df50 {
    void* value;
    Static1df50() { construct(this, &descriptor); }
    ~Static1df50() { destroy(this); }
};
