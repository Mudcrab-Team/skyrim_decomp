// Source exposure: binary-analysis; no external implementation source reused.
// Static175fc60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fc60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fc60*);
    virtual void release(Static175fc60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fc60*);
struct Static175fc60 {
    void* value;
    Static175fc60();
    ~Static175fc60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
