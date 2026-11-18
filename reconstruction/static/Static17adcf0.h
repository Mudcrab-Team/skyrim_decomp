// Source exposure: binary-analysis; no external implementation source reused.
// Static17adcf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17adcf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17adcf0*);
    virtual void release(Static17adcf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17adcf0*);
struct Static17adcf0 {
    void* value;
    Static17adcf0();
    ~Static17adcf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
