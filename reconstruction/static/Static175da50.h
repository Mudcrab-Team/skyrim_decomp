// Source exposure: binary-analysis; no external implementation source reused.
// Static175da50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175da50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175da50*);
    virtual void release(Static175da50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175da50*);
struct Static175da50 {
    void* value;
    Static175da50();
    ~Static175da50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
