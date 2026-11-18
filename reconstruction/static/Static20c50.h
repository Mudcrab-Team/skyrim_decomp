// Source exposure: binary-analysis
// Static20c50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20c50;
extern void construct(Static20c50*, const Descriptor*);
extern void destroy(Static20c50*);
struct Static20c50 {
    void* value;
    Static20c50() { construct(this, &descriptor); }
    ~Static20c50() { destroy(this); }
};
