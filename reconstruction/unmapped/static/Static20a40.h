// Source exposure: binary-analysis
// Static20a40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20a40;
extern void construct(Static20a40*, const Descriptor*);
extern void destroy(Static20a40*);
struct Static20a40 {
    void* value;
    Static20a40() { construct(this, &descriptor); }
    ~Static20a40() { destroy(this); }
};
