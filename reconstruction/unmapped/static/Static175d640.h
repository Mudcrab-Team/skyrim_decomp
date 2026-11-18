// Source exposure: binary-analysis; no external implementation source reused.
// Static175d640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d640*);
    virtual void release(Static175d640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d640*);
struct Static175d640 {
    void* value;
    Static175d640();
    ~Static175d640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
