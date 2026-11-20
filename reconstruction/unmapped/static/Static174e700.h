// Source exposure: binary-analysis; no external implementation source reused.
// Static174e700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e700*);
    virtual void release(Static174e700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e700*);
struct Static174e700 {
    void* value;
    Static174e700();
    ~Static174e700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
