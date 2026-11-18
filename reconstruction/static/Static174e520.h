// Source exposure: binary-analysis; no external implementation source reused.
// Static174e520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e520*);
    virtual void release(Static174e520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e520*);
struct Static174e520 {
    void* value;
    Static174e520();
    ~Static174e520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
