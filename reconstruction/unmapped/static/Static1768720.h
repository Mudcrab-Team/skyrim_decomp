// Source exposure: binary-analysis; no external implementation source reused.
// Static1768720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768720*);
    virtual void release(Static1768720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768720*);
struct Static1768720 {
    void* value;
    Static1768720();
    ~Static1768720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
