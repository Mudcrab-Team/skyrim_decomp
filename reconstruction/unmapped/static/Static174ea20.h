// Source exposure: binary-analysis; no external implementation source reused.
// Static174ea20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ea20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ea20*);
    virtual void release(Static174ea20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ea20*);
struct Static174ea20 {
    void* value;
    Static174ea20();
    ~Static174ea20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
