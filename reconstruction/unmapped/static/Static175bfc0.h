// Source exposure: binary-analysis; no external implementation source reused.
// Static175bfc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bfc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bfc0*);
    virtual void release(Static175bfc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bfc0*);
struct Static175bfc0 {
    void* value;
    Static175bfc0();
    ~Static175bfc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
