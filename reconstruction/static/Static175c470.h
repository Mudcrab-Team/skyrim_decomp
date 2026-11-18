// Source exposure: binary-analysis; no external implementation source reused.
// Static175c470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c470*);
    virtual void release(Static175c470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c470*);
struct Static175c470 {
    void* value;
    Static175c470();
    ~Static175c470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
