// Source exposure: binary-analysis; no external implementation source reused.
// Static175edb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175edb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175edb0*);
    virtual void release(Static175edb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175edb0*);
struct Static175edb0 {
    void* value;
    Static175edb0();
    ~Static175edb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
