// Source exposure: binary-analysis; no external implementation source reused.
// Static175d820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d820*);
    virtual void release(Static175d820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d820*);
struct Static175d820 {
    void* value;
    Static175d820();
    ~Static175d820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
