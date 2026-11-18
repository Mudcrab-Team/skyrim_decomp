// Source exposure: binary-analysis; no external implementation source reused.
// Static175bb60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bb60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bb60*);
    virtual void release(Static175bb60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bb60*);
struct Static175bb60 {
    void* value;
    Static175bb60();
    ~Static175bb60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
