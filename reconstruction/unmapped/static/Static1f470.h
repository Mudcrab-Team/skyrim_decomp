// Source exposure: binary-analysis
// Static1f470, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1f470;
extern void construct(Static1f470*, const Descriptor*);
extern void destroy(Static1f470*);
struct Static1f470 {
    void* value;
    Static1f470() { construct(this, &descriptor); }
    ~Static1f470() { destroy(this); }
};
