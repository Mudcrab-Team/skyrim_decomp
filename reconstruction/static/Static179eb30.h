// Source exposure: binary-analysis; no external implementation source reused.
// Static179eb30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179eb30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179eb30*);
    virtual void release(Static179eb30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179eb30*);
struct Static179eb30 {
    void* value;
    Static179eb30();
    ~Static179eb30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
