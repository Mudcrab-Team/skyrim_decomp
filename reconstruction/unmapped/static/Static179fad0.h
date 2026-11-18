// Source exposure: binary-analysis; no external implementation source reused.
// Static179fad0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179fad0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179fad0*);
    virtual void release(Static179fad0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179fad0*);
struct Static179fad0 {
    void* value;
    Static179fad0();
    ~Static179fad0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
