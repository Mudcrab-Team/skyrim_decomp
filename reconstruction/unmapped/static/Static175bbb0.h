// Source exposure: binary-analysis; no external implementation source reused.
// Static175bbb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bbb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bbb0*);
    virtual void release(Static175bbb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bbb0*);
struct Static175bbb0 {
    void* value;
    Static175bbb0();
    ~Static175bbb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
