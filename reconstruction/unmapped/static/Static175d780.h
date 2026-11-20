// Source exposure: binary-analysis; no external implementation source reused.
// Static175d780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d780*);
    virtual void release(Static175d780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d780*);
struct Static175d780 {
    void* value;
    Static175d780();
    ~Static175d780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
