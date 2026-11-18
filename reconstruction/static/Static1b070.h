// Source exposure: binary-analysis
// Static1b070, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b070;
extern void construct(Static1b070*, const Descriptor*);
extern void destroy(Static1b070*);
struct Static1b070 {
    void* value;
    Static1b070() { construct(this, &descriptor); }
    ~Static1b070() { destroy(this); }
};
