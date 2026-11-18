// Source exposure: binary-analysis; no external implementation source reused.
// Static17adc20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17adc20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17adc20*);
    virtual void release(Static17adc20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17adc20*);
struct Static17adc20 {
    void* value;
    Static17adc20();
    ~Static17adc20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
