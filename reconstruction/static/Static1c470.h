// Source exposure: binary-analysis
// Static1c470, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1c470;
extern void construct(Static1c470*, const Descriptor*);
extern void destroy(Static1c470*);
struct Static1c470 {
    void* value;
    Static1c470() { construct(this, &descriptor); }
    ~Static1c470() { destroy(this); }
};
