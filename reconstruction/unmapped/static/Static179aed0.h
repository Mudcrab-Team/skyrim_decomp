// Source exposure: binary-analysis; no external implementation source reused.
// Static179aed0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179aed0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179aed0*);
    virtual void release(Static179aed0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179aed0*);
struct Static179aed0 {
    void* value;
    Static179aed0();
    ~Static179aed0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
