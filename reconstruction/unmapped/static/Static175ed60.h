// Source exposure: binary-analysis; no external implementation source reused.
// Static175ed60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ed60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ed60*);
    virtual void release(Static175ed60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ed60*);
struct Static175ed60 {
    void* value;
    Static175ed60();
    ~Static175ed60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
