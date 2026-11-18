// Source exposure: binary-analysis; no external implementation source reused.
// Static179cfa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179cfa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179cfa0*);
    virtual void release(Static179cfa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179cfa0*);
struct Static179cfa0 {
    void* value;
    Static179cfa0();
    ~Static179cfa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
