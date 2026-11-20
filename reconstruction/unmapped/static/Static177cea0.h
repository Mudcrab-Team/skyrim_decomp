// Source exposure: binary-analysis; no external implementation source reused.
// Static177cea0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cea0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cea0*);
    virtual void release(Static177cea0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cea0*);
struct Static177cea0 {
    void* value;
    Static177cea0();
    ~Static177cea0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
