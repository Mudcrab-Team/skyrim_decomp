// Source exposure: binary-analysis; no external implementation source reused.
// Static177a920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a920*);
    virtual void release(Static177a920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a920*);
struct Static177a920 {
    void* value;
    Static177a920();
    ~Static177a920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
