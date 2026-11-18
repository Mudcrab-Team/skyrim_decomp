// Source exposure: binary-analysis; no external implementation source reused.
// Static175a580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a580*);
    virtual void release(Static175a580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a580*);
struct Static175a580 {
    void* value;
    Static175a580();
    ~Static175a580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
