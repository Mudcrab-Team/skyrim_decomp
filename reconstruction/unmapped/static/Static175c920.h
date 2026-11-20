// Source exposure: binary-analysis; no external implementation source reused.
// Static175c920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c920*);
    virtual void release(Static175c920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c920*);
struct Static175c920 {
    void* value;
    Static175c920();
    ~Static175c920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
