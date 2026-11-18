// Source exposure: binary-analysis; no external implementation source reused.
// Static179d910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d910*);
    virtual void release(Static179d910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d910*);
struct Static179d910 {
    void* value;
    Static179d910();
    ~Static179d910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
