// Source exposure: binary-analysis; no external implementation source reused.
// Static175aad0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175aad0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175aad0*);
    virtual void release(Static175aad0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175aad0*);
struct Static175aad0 {
    void* value;
    Static175aad0();
    ~Static175aad0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
