// Source exposure: binary-analysis; no external implementation source reused.
// Static175d730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d730*);
    virtual void release(Static175d730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d730*);
struct Static175d730 {
    void* value;
    Static175d730();
    ~Static175d730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
