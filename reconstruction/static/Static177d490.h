// Source exposure: binary-analysis; no external implementation source reused.
// Static177d490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d490*);
    virtual void release(Static177d490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d490*);
struct Static177d490 {
    void* value;
    Static177d490();
    ~Static177d490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
