// Source exposure: binary-analysis; no external implementation source reused.
// Static177a880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a880*);
    virtual void release(Static177a880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a880*);
struct Static177a880 {
    void* value;
    Static177a880();
    ~Static177a880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
