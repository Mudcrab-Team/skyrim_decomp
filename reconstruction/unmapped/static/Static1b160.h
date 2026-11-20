// Source exposure: binary-analysis
// Static1b160, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b160;
extern void construct(Static1b160*, const Descriptor*);
extern void destroy(Static1b160*);
struct Static1b160 {
    void* value;
    Static1b160() { construct(this, &descriptor); }
    ~Static1b160() { destroy(this); }
};
