// Source exposure: binary-analysis; no external implementation source reused.
// Static179bee0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179bee0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179bee0*);
    virtual void release(Static179bee0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179bee0*);
struct Static179bee0 {
    void* value;
    Static179bee0();
    ~Static179bee0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
