// Source exposure: binary-analysis; no external implementation source reused.
// Static175d230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d230*);
    virtual void release(Static175d230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d230*);
struct Static175d230 {
    void* value;
    Static175d230();
    ~Static175d230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
