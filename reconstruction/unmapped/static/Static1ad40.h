// Source exposure: binary-analysis
// Static1ad40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ad40;
extern void construct(Static1ad40*, const Descriptor*);
extern void destroy(Static1ad40*);
struct Static1ad40 {
    void* value;
    Static1ad40() { construct(this, &descriptor); }
    ~Static1ad40() { destroy(this); }
};
