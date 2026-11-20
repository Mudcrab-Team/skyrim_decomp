// Source exposure: binary-analysis; no external implementation source reused.
// Static175d500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d500*);
    virtual void release(Static175d500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d500*);
struct Static175d500 {
    void* value;
    Static175d500();
    ~Static175d500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
