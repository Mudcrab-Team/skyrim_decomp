// Source exposure: binary-analysis; no external implementation source reused.
// Static175cf60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cf60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cf60*);
    virtual void release(Static175cf60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cf60*);
struct Static175cf60 {
    void* value;
    Static175cf60();
    ~Static175cf60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
