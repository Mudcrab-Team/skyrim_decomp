// Source exposure: binary-analysis; no external implementation source reused.
// Static175f260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f260*);
    virtual void release(Static175f260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f260*);
struct Static175f260 {
    void* value;
    Static175f260();
    ~Static175f260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
