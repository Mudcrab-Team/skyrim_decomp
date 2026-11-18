// Source exposure: binary-analysis; no external implementation source reused.
// Static175dbe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175dbe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175dbe0*);
    virtual void release(Static175dbe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175dbe0*);
struct Static175dbe0 {
    void* value;
    Static175dbe0();
    ~Static175dbe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
