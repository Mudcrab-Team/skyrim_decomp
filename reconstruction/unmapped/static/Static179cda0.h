// Source exposure: binary-analysis; no external implementation source reused.
// Static179cda0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179cda0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179cda0*);
    virtual void release(Static179cda0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179cda0*);
struct Static179cda0 {
    void* value;
    Static179cda0();
    ~Static179cda0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
