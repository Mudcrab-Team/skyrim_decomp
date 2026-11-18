// Source exposure: binary-analysis
// Static1e220, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1e220;
extern void construct(Static1e220*, const Descriptor*);
extern void destroy(Static1e220*);
struct Static1e220 {
    void* value;
    Static1e220() { construct(this, &descriptor); }
    ~Static1e220() { destroy(this); }
};
