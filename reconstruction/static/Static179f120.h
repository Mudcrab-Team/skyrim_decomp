// Source exposure: binary-analysis; no external implementation source reused.
// Static179f120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f120*);
    virtual void release(Static179f120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f120*);
struct Static179f120 {
    void* value;
    Static179f120();
    ~Static179f120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
