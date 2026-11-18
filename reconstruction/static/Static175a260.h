// Source exposure: binary-analysis; no external implementation source reused.
// Static175a260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a260*);
    virtual void release(Static175a260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a260*);
struct Static175a260 {
    void* value;
    Static175a260();
    ~Static175a260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
