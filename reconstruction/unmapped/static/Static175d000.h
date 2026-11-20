// Source exposure: binary-analysis; no external implementation source reused.
// Static175d000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d000*);
    virtual void release(Static175d000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d000*);
struct Static175d000 {
    void* value;
    Static175d000();
    ~Static175d000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
