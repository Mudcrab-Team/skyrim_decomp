// Source exposure: binary-analysis; no external implementation source reused.
// Static179c020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c020*);
    virtual void release(Static179c020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c020*);
struct Static179c020 {
    void* value;
    Static179c020();
    ~Static179c020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
