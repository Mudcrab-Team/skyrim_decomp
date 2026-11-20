// Source exposure: binary-analysis; no external implementation source reused.
// Static175ab70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ab70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ab70*);
    virtual void release(Static175ab70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ab70*);
struct Static175ab70 {
    void* value;
    Static175ab70();
    ~Static175ab70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
