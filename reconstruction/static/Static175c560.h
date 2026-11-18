// Source exposure: binary-analysis; no external implementation source reused.
// Static175c560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c560*);
    virtual void release(Static175c560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c560*);
struct Static175c560 {
    void* value;
    Static175c560();
    ~Static175c560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
