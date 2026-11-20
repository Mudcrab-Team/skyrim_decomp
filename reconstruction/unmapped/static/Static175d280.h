// Source exposure: binary-analysis; no external implementation source reused.
// Static175d280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d280*);
    virtual void release(Static175d280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d280*);
struct Static175d280 {
    void* value;
    Static175d280();
    ~Static175d280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
