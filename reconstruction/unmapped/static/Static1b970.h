// Source exposure: binary-analysis
// Static1b970, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b970;
extern void construct(Static1b970*, const Descriptor*);
extern void destroy(Static1b970*);
struct Static1b970 {
    void* value;
    Static1b970() { construct(this, &descriptor); }
    ~Static1b970() { destroy(this); }
};
