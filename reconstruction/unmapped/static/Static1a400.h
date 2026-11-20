// Source exposure: binary-analysis
// Static1a400, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1a400;
extern void construct(Static1a400*, const Descriptor*);
extern void destroy(Static1a400*);
struct Static1a400 {
    void* value;
    Static1a400() { construct(this, &descriptor); }
    ~Static1a400() { destroy(this); }
};
