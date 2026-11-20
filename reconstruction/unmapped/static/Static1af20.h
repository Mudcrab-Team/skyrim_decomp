// Source exposure: binary-analysis
// Static1af20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1af20;
extern void construct(Static1af20*, const Descriptor*);
extern void destroy(Static1af20*);
struct Static1af20 {
    void* value;
    Static1af20() { construct(this, &descriptor); }
    ~Static1af20() { destroy(this); }
};
