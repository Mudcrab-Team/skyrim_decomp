// Source exposure: binary-analysis
// Static1d800, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d800;
extern void construct(Static1d800*, const Descriptor*);
extern void destroy(Static1d800*);
struct Static1d800 {
    void* value;
    Static1d800() { construct(this, &descriptor); }
    ~Static1d800() { destroy(this); }
};
