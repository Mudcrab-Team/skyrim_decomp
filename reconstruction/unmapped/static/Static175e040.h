// Source exposure: binary-analysis; no external implementation source reused.
// Static175e040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e040*);
    virtual void release(Static175e040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e040*);
struct Static175e040 {
    void* value;
    Static175e040();
    ~Static175e040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
