// Source exposure: binary-analysis; no external implementation source reused.
// Static179eae0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179eae0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179eae0*);
    virtual void release(Static179eae0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179eae0*);
struct Static179eae0 {
    void* value;
    Static179eae0();
    ~Static179eae0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
