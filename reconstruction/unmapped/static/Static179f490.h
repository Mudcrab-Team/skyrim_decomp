// Source exposure: binary-analysis; no external implementation source reused.
// Static179f490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f490*);
    virtual void release(Static179f490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f490*);
struct Static179f490 {
    void* value;
    Static179f490();
    ~Static179f490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
