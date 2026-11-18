// Source exposure: binary-analysis; no external implementation source reused.
// Static175ebd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ebd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ebd0*);
    virtual void release(Static175ebd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ebd0*);
struct Static175ebd0 {
    void* value;
    Static175ebd0();
    ~Static175ebd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
