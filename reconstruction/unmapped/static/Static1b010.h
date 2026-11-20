// Source exposure: binary-analysis
// Static1b010, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b010;
extern void construct(Static1b010*, const Descriptor*);
extern void destroy(Static1b010*);
struct Static1b010 {
    void* value;
    Static1b010() { construct(this, &descriptor); }
    ~Static1b010() { destroy(this); }
};
