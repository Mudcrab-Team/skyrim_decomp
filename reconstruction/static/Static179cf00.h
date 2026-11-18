// Source exposure: binary-analysis; no external implementation source reused.
// Static179cf00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179cf00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179cf00*);
    virtual void release(Static179cf00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179cf00*);
struct Static179cf00 {
    void* value;
    Static179cf00();
    ~Static179cf00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
