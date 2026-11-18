// Source exposure: binary-analysis
// Static1af80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1af80;
extern void construct(Static1af80*, const Descriptor*);
extern void destroy(Static1af80*);
struct Static1af80 {
    void* value;
    Static1af80() { construct(this, &descriptor); }
    ~Static1af80() { destroy(this); }
};
