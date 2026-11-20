// Source exposure: binary-analysis
// Static1ac50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ac50;
extern void construct(Static1ac50*, const Descriptor*);
extern void destroy(Static1ac50*);
struct Static1ac50 {
    void* value;
    Static1ac50() { construct(this, &descriptor); }
    ~Static1ac50() { destroy(this); }
};
