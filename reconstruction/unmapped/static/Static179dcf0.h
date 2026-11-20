// Source exposure: binary-analysis; no external implementation source reused.
// Static179dcf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179dcf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179dcf0*);
    virtual void release(Static179dcf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179dcf0*);
struct Static179dcf0 {
    void* value;
    Static179dcf0();
    ~Static179dcf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
