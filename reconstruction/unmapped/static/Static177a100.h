// Source exposure: binary-analysis; no external implementation source reused.
// Static177a100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a100*);
    virtual void release(Static177a100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a100*);
struct Static177a100 {
    void* value;
    Static177a100();
    ~Static177a100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
