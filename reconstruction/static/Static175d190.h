// Source exposure: binary-analysis; no external implementation source reused.
// Static175d190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d190*);
    virtual void release(Static175d190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d190*);
struct Static175d190 {
    void* value;
    Static175d190();
    ~Static175d190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
