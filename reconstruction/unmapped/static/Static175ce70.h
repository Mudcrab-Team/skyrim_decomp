// Source exposure: binary-analysis; no external implementation source reused.
// Static175ce70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ce70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ce70*);
    virtual void release(Static175ce70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ce70*);
struct Static175ce70 {
    void* value;
    Static175ce70();
    ~Static175ce70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
