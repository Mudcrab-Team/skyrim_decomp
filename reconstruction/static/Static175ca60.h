// Source exposure: binary-analysis; no external implementation source reused.
// Static175ca60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ca60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ca60*);
    virtual void release(Static175ca60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ca60*);
struct Static175ca60 {
    void* value;
    Static175ca60();
    ~Static175ca60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
