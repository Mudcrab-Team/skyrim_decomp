// Source exposure: binary-analysis; no external implementation source reused.
// Static174ea70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ea70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ea70*);
    virtual void release(Static174ea70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ea70*);
struct Static174ea70 {
    void* value;
    Static174ea70();
    ~Static174ea70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
