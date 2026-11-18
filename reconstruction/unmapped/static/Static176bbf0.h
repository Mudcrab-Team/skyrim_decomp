// Source exposure: binary-analysis; no external implementation source reused.
// Static176bbf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bbf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bbf0*);
    virtual void release(Static176bbf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bbf0*);
struct Static176bbf0 {
    void* value;
    Static176bbf0();
    ~Static176bbf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
