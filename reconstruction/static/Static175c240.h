// Source exposure: binary-analysis; no external implementation source reused.
// Static175c240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c240*);
    virtual void release(Static175c240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c240*);
struct Static175c240 {
    void* value;
    Static175c240();
    ~Static175c240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
