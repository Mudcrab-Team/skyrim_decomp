// Source exposure: binary-analysis; no external implementation source reused.
// Static17737b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17737b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17737b0*);
    virtual void release(Static17737b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17737b0*);
struct Static17737b0 {
    void* value;
    Static17737b0();
    ~Static17737b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
