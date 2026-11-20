// Source exposure: binary-analysis
// Static1db90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1db90;
extern void construct(Static1db90*, const Descriptor*);
extern void destroy(Static1db90*);
struct Static1db90 {
    void* value;
    Static1db90() { construct(this, &descriptor); }
    ~Static1db90() { destroy(this); }
};
