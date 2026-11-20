// Source exposure: binary-analysis; no external implementation source reused.
// Static174dc80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174dc80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174dc80*);
    virtual void release(Static174dc80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174dc80*);
struct Static174dc80 {
    void* value;
    Static174dc80();
    ~Static174dc80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
