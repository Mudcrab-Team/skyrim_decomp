// Source exposure: binary-analysis; no external implementation source reused.
// Static177c720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c720*);
    virtual void release(Static177c720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c720*);
struct Static177c720 {
    void* value;
    Static177c720();
    ~Static177c720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
