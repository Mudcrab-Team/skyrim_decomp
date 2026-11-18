// Source exposure: binary-analysis
// Static1d740, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d740;
extern void construct(Static1d740*, const Descriptor*);
extern void destroy(Static1d740*);
struct Static1d740 {
    void* value;
    Static1d740() { construct(this, &descriptor); }
    ~Static1d740() { destroy(this); }
};
