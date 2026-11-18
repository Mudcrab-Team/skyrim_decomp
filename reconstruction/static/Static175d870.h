// Source exposure: binary-analysis; no external implementation source reused.
// Static175d870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d870*);
    virtual void release(Static175d870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d870*);
struct Static175d870 {
    void* value;
    Static175d870();
    ~Static175d870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
