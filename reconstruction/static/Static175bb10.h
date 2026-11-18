// Source exposure: binary-analysis; no external implementation source reused.
// Static175bb10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bb10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bb10*);
    virtual void release(Static175bb10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bb10*);
struct Static175bb10 {
    void* value;
    Static175bb10();
    ~Static175bb10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
