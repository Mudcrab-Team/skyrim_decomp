// Source exposure: binary-analysis
// Staticc5450, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc5450;
extern void construct(Staticc5450*, const Descriptor*);
extern void destroy(Staticc5450*);
struct Staticc5450 {
    void* value;
    Staticc5450() { construct(this, &descriptor); }
    ~Staticc5450() { destroy(this); }
};
