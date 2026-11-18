// Source exposure: binary-analysis; no external implementation source reused.
// Static175bca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bca0*);
    virtual void release(Static175bca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bca0*);
struct Static175bca0 {
    void* value;
    Static175bca0();
    ~Static175bca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
