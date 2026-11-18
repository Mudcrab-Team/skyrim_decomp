// Source exposure: binary-analysis; no external implementation source reused.
// Static175fe40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fe40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fe40*);
    virtual void release(Static175fe40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fe40*);
struct Static175fe40 {
    void* value;
    Static175fe40();
    ~Static175fe40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
