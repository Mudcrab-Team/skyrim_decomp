// Source exposure: binary-analysis; no external implementation source reused.
// Static175a760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a760*);
    virtual void release(Static175a760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a760*);
struct Static175a760 {
    void* value;
    Static175a760();
    ~Static175a760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
