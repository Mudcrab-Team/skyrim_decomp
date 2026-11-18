// Source exposure: binary-analysis
// Static1b400, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b400;
extern void construct(Static1b400*, const Descriptor*);
extern void destroy(Static1b400*);
struct Static1b400 {
    void* value;
    Static1b400() { construct(this, &descriptor); }
    ~Static1b400() { destroy(this); }
};
