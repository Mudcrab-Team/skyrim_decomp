// Source exposure: binary-analysis
// Static1ad10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ad10;
extern void construct(Static1ad10*, const Descriptor*);
extern void destroy(Static1ad10*);
struct Static1ad10 {
    void* value;
    Static1ad10() { construct(this, &descriptor); }
    ~Static1ad10() { destroy(this); }
};
