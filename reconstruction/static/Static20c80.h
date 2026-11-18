// Source exposure: binary-analysis
// Static20c80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20c80;
extern void construct(Static20c80*, const Descriptor*);
extern void destroy(Static20c80*);
struct Static20c80 {
    void* value;
    Static20c80() { construct(this, &descriptor); }
    ~Static20c80() { destroy(this); }
};
