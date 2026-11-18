// Source exposure: binary-analysis; no external implementation source reused.
// Static175d050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d050*);
    virtual void release(Static175d050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d050*);
struct Static175d050 {
    void* value;
    Static175d050();
    ~Static175d050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
