// Source exposure: binary-analysis; no external implementation source reused.
// Static175d140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d140*);
    virtual void release(Static175d140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d140*);
struct Static175d140 {
    void* value;
    Static175d140();
    ~Static175d140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
