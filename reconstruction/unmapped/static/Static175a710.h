// Source exposure: binary-analysis; no external implementation source reused.
// Static175a710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a710*);
    virtual void release(Static175a710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a710*);
struct Static175a710 {
    void* value;
    Static175a710();
    ~Static175a710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
