// Source exposure: binary-analysis
// Static1db30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1db30;
extern void construct(Static1db30*, const Descriptor*);
extern void destroy(Static1db30*);
struct Static1db30 {
    void* value;
    Static1db30() { construct(this, &descriptor); }
    ~Static1db30() { destroy(this); }
};
