// Source exposure: binary-analysis; no external implementation source reused.
// Static175c380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c380*);
    virtual void release(Static175c380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c380*);
struct Static175c380 {
    void* value;
    Static175c380();
    ~Static175c380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
