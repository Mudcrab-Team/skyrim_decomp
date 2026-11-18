// Source exposure: binary-analysis; no external implementation source reused.
// Static177a510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a510*);
    virtual void release(Static177a510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a510*);
struct Static177a510 {
    void* value;
    Static177a510();
    ~Static177a510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
