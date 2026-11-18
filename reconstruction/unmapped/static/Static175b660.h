// Source exposure: binary-analysis; no external implementation source reused.
// Static175b660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b660*);
    virtual void release(Static175b660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b660*);
struct Static175b660 {
    void* value;
    Static175b660();
    ~Static175b660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
