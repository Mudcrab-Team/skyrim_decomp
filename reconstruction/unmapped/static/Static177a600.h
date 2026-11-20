// Source exposure: binary-analysis; no external implementation source reused.
// Static177a600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a600*);
    virtual void release(Static177a600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a600*);
struct Static177a600 {
    void* value;
    Static177a600();
    ~Static177a600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
