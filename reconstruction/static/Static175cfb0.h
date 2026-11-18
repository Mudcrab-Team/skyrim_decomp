// Source exposure: binary-analysis; no external implementation source reused.
// Static175cfb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cfb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cfb0*);
    virtual void release(Static175cfb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cfb0*);
struct Static175cfb0 {
    void* value;
    Static175cfb0();
    ~Static175cfb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
