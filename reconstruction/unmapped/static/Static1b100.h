// Source exposure: binary-analysis
// Static1b100, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b100;
extern void construct(Static1b100*, const Descriptor*);
extern void destroy(Static1b100*);
struct Static1b100 {
    void* value;
    Static1b100() { construct(this, &descriptor); }
    ~Static1b100() { destroy(this); }
};
