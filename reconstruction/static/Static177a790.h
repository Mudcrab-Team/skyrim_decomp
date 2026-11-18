// Source exposure: binary-analysis; no external implementation source reused.
// Static177a790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a790*);
    virtual void release(Static177a790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a790*);
struct Static177a790 {
    void* value;
    Static177a790();
    ~Static177a790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
