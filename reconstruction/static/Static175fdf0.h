// Source exposure: binary-analysis; no external implementation source reused.
// Static175fdf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fdf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fdf0*);
    virtual void release(Static175fdf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fdf0*);
struct Static175fdf0 {
    void* value;
    Static175fdf0();
    ~Static175fdf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
