// Source exposure: binary-analysis
// Static1e070, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1e070;
extern void construct(Static1e070*, const Descriptor*);
extern void destroy(Static1e070*);
struct Static1e070 {
    void* value;
    Static1e070() { construct(this, &descriptor); }
    ~Static1e070() { destroy(this); }
};
