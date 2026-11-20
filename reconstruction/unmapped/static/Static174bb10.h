// Source exposure: binary-analysis; no external implementation source reused.
// Static174bb10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bb10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bb10*);
    virtual void release(Static174bb10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bb10*);
struct Static174bb10 {
    void* value;
    Static174bb10();
    ~Static174bb10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
