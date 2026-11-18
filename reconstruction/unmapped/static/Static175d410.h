// Source exposure: binary-analysis; no external implementation source reused.
// Static175d410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d410*);
    virtual void release(Static175d410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d410*);
struct Static175d410 {
    void* value;
    Static175d410();
    ~Static175d410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
