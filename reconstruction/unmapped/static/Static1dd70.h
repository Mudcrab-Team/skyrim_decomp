// Source exposure: binary-analysis
// Static1dd70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dd70;
extern void construct(Static1dd70*, const Descriptor*);
extern void destroy(Static1dd70*);
struct Static1dd70 {
    void* value;
    Static1dd70() { construct(this, &descriptor); }
    ~Static1dd70() { destroy(this); }
};
