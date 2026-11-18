// Source exposure: binary-analysis; no external implementation source reused.
// Static179eea0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179eea0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179eea0*);
    virtual void release(Static179eea0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179eea0*);
struct Static179eea0 {
    void* value;
    Static179eea0();
    ~Static179eea0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
