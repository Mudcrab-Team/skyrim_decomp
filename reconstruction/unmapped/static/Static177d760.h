// Source exposure: binary-analysis; no external implementation source reused.
// Static177d760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d760*);
    virtual void release(Static177d760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d760*);
struct Static177d760 {
    void* value;
    Static177d760();
    ~Static177d760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
