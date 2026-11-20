// Source exposure: binary-analysis; no external implementation source reused.
// Static176ead0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ead0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ead0*);
    virtual void release(Static176ead0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ead0*);
struct Static176ead0 {
    void* value;
    Static176ead0();
    ~Static176ead0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
