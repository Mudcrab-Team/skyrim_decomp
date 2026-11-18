// Source exposure: binary-analysis
// Static1ac80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ac80;
extern void construct(Static1ac80*, const Descriptor*);
extern void destroy(Static1ac80*);
struct Static1ac80 {
    void* value;
    Static1ac80() { construct(this, &descriptor); }
    ~Static1ac80() { destroy(this); }
};
