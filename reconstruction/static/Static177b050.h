// Source exposure: binary-analysis; no external implementation source reused.
// Static177b050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b050*);
    virtual void release(Static177b050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b050*);
struct Static177b050 {
    void* value;
    Static177b050();
    ~Static177b050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
