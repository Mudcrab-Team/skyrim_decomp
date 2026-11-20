// Source exposure: binary-analysis
// Static1db60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1db60;
extern void construct(Static1db60*, const Descriptor*);
extern void destroy(Static1db60*);
struct Static1db60 {
    void* value;
    Static1db60() { construct(this, &descriptor); }
    ~Static1db60() { destroy(this); }
};
