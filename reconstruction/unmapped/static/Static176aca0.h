// Source exposure: binary-analysis; no external implementation source reused.
// Static176aca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176aca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176aca0*);
    virtual void release(Static176aca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176aca0*);
struct Static176aca0 {
    void* value;
    Static176aca0();
    ~Static176aca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
