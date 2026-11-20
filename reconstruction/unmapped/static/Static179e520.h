// Source exposure: binary-analysis; no external implementation source reused.
// Static179e520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e520*);
    virtual void release(Static179e520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e520*);
struct Static179e520 {
    void* value;
    Static179e520();
    ~Static179e520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
