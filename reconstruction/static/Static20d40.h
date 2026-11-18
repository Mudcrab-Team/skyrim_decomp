// Source exposure: binary-analysis
// Static20d40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20d40;
extern void construct(Static20d40*, const Descriptor*);
extern void destroy(Static20d40*);
struct Static20d40 {
    void* value;
    Static20d40() { construct(this, &descriptor); }
    ~Static20d40() { destroy(this); }
};
