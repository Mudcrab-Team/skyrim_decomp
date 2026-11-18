// Source exposure: binary-analysis; no external implementation source reused.
// Static179ae30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ae30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ae30*);
    virtual void release(Static179ae30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ae30*);
struct Static179ae30 {
    void* value;
    Static179ae30();
    ~Static179ae30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
