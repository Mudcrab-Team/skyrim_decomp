// Source exposure: binary-analysis; no external implementation source reused.
// Static179afc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179afc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179afc0*);
    virtual void release(Static179afc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179afc0*);
struct Static179afc0 {
    void* value;
    Static179afc0();
    ~Static179afc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
