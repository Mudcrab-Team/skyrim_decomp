// Source exposure: binary-analysis; no external implementation source reused.
// Static177a010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a010*);
    virtual void release(Static177a010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a010*);
struct Static177a010 {
    void* value;
    Static177a010();
    ~Static177a010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
