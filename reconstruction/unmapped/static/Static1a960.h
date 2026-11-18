// Source exposure: binary-analysis
// Static1a960, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1a960;
extern void construct(Static1a960*, const Descriptor*);
extern void destroy(Static1a960*);
struct Static1a960 {
    void* value;
    Static1a960() { construct(this, &descriptor); }
    ~Static1a960() { destroy(this); }
};
